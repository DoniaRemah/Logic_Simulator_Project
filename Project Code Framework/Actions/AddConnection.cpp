#include "AddConnection.h"
#include "..\ApplicationManager.h"
AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
	SrcPin = NULL;
	DstPin = NULL;
	IsCancelled = false;
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

		pIn->GetPointClicked(x1, y1);
		validSource = CheckValidSrc(CompList,Comp_Count, validOutPin,SrcPin);
		if (validSource == false)
		{
			pOut->PrintMsg("INVALID AREA. Operation Cancelled.");
			IsCancelled = true;
		}
		else if (validOutPin == false)
		{
			pOut->PrintMsg("INVALID OUTPUT PIN. Operation Cancelled.");
			IsCancelled = true;
		}

		if (IsCancelled == false)
		{
			// Checking if user clicked on valid DST Gate.
			bool validDst = 0;
			bool validInPin = 0;
			pOut->PrintMsg("ADDING CONNECTION. Click on DESTINATION  Component.");

			pIn->GetPointClicked(x2, y2);
			validDst = CheckValidDst(CompList, Comp_Count, validInPin, DstPin);
			if (validDst == 0)
			{
				pOut->PrintMsg("INVALID AREA. Operation Cancelled.");
				IsCancelled = true;
			}
			else if (validInPin == false)
			{
				pOut->PrintMsg("INVALID: PIN/S ALREADY CONNECTED. Operation Cancelled.");
				IsCancelled = true;
			}
			else
			{
				pOut->PrintMsg("Connection Added. Click on Next Action");
			}
		
		}
	
		

}

void  AddConnection::Execute()
{

		ReadActionParameters();
if (IsCancelled == false)
	{
		// Calculating Parameters of Connection
		GraphicsInfo GInfo;
		GInfo.x1 = m_SrcComp->GetGfxInfo().x2;
		GInfo.x2 = m_DstComp->GetGfxInfo().x1;
		GInfo.y1 = m_SrcComp->GetGfxInfo().y1 + (m_SrcComp->GetGfxInfo().y2 - m_SrcComp->GetGfxInfo().y1) / 2;
		
		if (m_DstComp->GetNoInputPins() == 2) // If Number of Pins is 2
		{
			if (AvailablePinNumber == 1) 
			{
				GInfo.y2 = m_DstComp->GetGfxInfo().y1 + ((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) / 3);
			}
			else 
			{
				GInfo.y2 = m_DstComp->GetGfxInfo().y1 + (((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) * 3) / 4);
			}
		}
		else if (m_DstComp->GetNoInputPins() == 1) // If Number of Pins is 1.
		{
			GInfo.y2 = m_DstComp->GetGfxInfo().y1 + ((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) / 2);
		}
		else if (m_DstComp->GetNoInputPins() == 3) // If Number of Pins is 3
		{
			if (AvailablePinNumber == 1)
			{
				GInfo.y2 = m_DstComp->GetGfxInfo().y1 + ((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) / 3);
			}
			else if (AvailablePinNumber ==2)
			{
				GInfo.y2 = m_DstComp->GetGfxInfo().y1 + ((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) / 2);
			}
			else
			{
				GInfo.y2 = m_DstComp->GetGfxInfo().y1 + (((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) * 3) / 4);
			}
		}

		// Creating Connection Pointer
		Connection* pA = new Connection(GInfo, NULL, NULL,m_SrcComp,m_DstComp);

		// Linking output pin of src component with src pin of connection.

		SrcPin->ConnectTo(pA);
		pA->setSourcePin(SrcPin);


		// Linking Input pin of Dst component with dst component of connection.

		pA->setDestPin(DstPin);
		DstPin->connect();


		// Adding Connection to Component List.
		pManager->AddComponent(pA);
	}

}



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
				for (int i = 1; i <= DstGate->GetNoInputPins() ; i++)
				{
					DstPin = DstGate->GetInputPin(i);
					isConnected = DstPin->IsConnected();

					if (isConnected)
					{
						validInPin = false;
					}
					else
					{
						validInPin = true;
						AvailablePinNumber = i;
						break;
					}
				}
				
			}

			

			break;
		}

	}
	return validDst;
}



void AddConnection::Undo()
{}

void AddConnection::Redo()
{}