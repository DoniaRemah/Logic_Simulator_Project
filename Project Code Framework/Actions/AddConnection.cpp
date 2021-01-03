#include "AddConnection.h"
#include "..\ApplicationManager.h"
AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
	SrcPin = NULL;
	DstPin = NULL;
}

AddConnection ::~AddConnection(void)
{

}

void AddConnection::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("ADDING CONNECTION. Click on SOURCE GATE.");

	// Getting List of Components on Screen
	int Comp_Count;
	Component** CompList = pManager->GetCompList(Comp_Count); 

	// Checking if user clicked on a valid source Gate.
	bool validSource = false;
	bool validOutPin = false;
	while (validSource == false || validOutPin == false)
	{
		pIn->GetPointClicked(x1, y1);
		validSource = CheckValidSrc(CompList,Comp_Count, validOutPin,SrcPin);
		if (validSource == false)
		{
			pOut->PrintMsg("INVALID AREA. click on SOURCE  Component.");
		}
		else if (validOutPin == false)
		{
			pOut->PrintMsg("INVALID OUTPUT PIN. click on another SOURCE  Component or DELETE one of the connections.");
		}
	}

	// Checking if user clicked on valid DST Gate.
	bool validDst = 0;
	bool validInPin = 0;
	pOut->PrintMsg("ADDING CONNECTION. Click on DESTINATION  Component.");
	while (validDst == 0 || validInPin == 0)
	{

		pIn->GetPointClicked(x2, y2);
		validDst = CheckValidDst(CompList, Comp_Count, validInPin, DstPin);
		if (validDst == 0)
		{
			pOut->PrintMsg("INVALID AREA. click on Destination GATE.");
		}
		else if (validInPin == false)
		{
			pOut->PrintMsg("INVALID: PIN/S ALREADY CONNECTED. click on ANOTHER Destination Component or DELETE connection.");
		}
	}
	pOut->ClearStatusBar();
}

void  AddConnection::Execute()
{
	ReadActionParameters();

	// Calculating Parameters of Connection
	GraphicsInfo GInfo;
	GInfo.x1 = m_SrcComp->GetGfxInfo().x2;
	GInfo.x2 = m_DstComp->GetGfxInfo().x1;
	GInfo.y1 = m_SrcComp->GetGfxInfo().y1+(m_SrcComp->GetGfxInfo().y2 - m_SrcComp->GetGfxInfo().y1)/2;
	GInfo.y2 = m_DstComp->GetGfxInfo().y1+((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) / 3);

	// Creating Connection Pointer
	Connection* pA = new Connection(GInfo, NULL ,NULL);

	// Linking output pin of src component with src pin of connection.
		SrcPin->ConnectTo(pA);
		pA->setSourcePin(SrcPin);
		

	// Linking Input pin of Dst component with dst component of connection.

		pA->setDestPin(DstPin);
		DstPin->connect();
		

	// Adding Connection to Component List.
	pManager->AddComponent(pA);

}

void AddConnection ::Undo()
{}

void AddConnection ::Redo()
{}

bool AddConnection::CheckValidSrc(Component** CompList,int Comp_Count, bool &validOutPin, OutputPin*& SrcPin)
{
	bool validcomp=false;
	for (int i = 0; i < Comp_Count; i++)
	{
		if (CompList[i]->InsideArea(x1, y1) == true)
		{
			validcomp = true;
			bool CanConnect;
			m_SrcComp = CompList[i];
			Gate* SrcGate = dynamic_cast<Gate*>(m_SrcComp);
			if (SrcGate == NULL)
			{
				SWITCH* SrcSwitch = dynamic_cast<SWITCH*>(m_SrcComp);
				SrcPin = SrcSwitch->GetOutputPin();
				CanConnect = SrcPin->CanConnect();
			}
			else
			{
				SrcPin = SrcGate->GetOutputPin();
				CanConnect = SrcPin->CanConnect();
			}
			if (CanConnect)
			{
				validOutPin = true;
			}
			else
			{
				validOutPin = false;
			}
			break;
		}
		
	}
	return validcomp;
}

bool AddConnection::CheckValidDst(Component** CompList, int Comp_Count, bool& validInPin, InputPin*&DstPin)
{
	bool validDst = false;
	for (int i = 0; i < Comp_Count; i++)
	{
		if (CompList[i]->InsideArea(x2, y2) == true)
		{
			validDst = 1;
			m_DstComp = CompList[i];
			bool isConnected;
			Gate* DstGate = dynamic_cast<Gate*>(m_DstComp);
			if (DstGate == NULL)
			{
				LED* DstLed = dynamic_cast<LED*>(m_DstComp);
				DstPin = DstLed->GetInputPin();
				isConnected = DstPin->IsConnected();
				if (isConnected)
				{
					validInPin = false;
				}
				else
				{
					validInPin = true;
					break;
				}
			}
			else
			{
				for (int i = 0; i < DstGate->GetNumberofInputPins() ; i++)
				{
					DstPin = DstGate->GetInputPin(i+1);
					isConnected = DstPin->IsConnected();

					if (isConnected)
					{
						validInPin = false;
					}
					else
					{
						validInPin = true;
						break;
					}
				}
				
			}

			

			break;
		}

	}
	return validDst;
}