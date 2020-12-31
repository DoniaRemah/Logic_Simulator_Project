#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include <iostream>
AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{

}

AddConnection ::~AddConnection(void)
{

}

void AddConnection::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("ADDING CONNECTION. Click on SOURCE GATE.");
	int Comp_Count;
	Component** CompList = pManager->GetCompList(Comp_Count); // Getting List of Components on Screen
	cout << "Component Count: " << Comp_Count << endl;
	int validSource = 0;
	while (validSource == 0)
	{
		cout << "In 1st While Loop" << endl;

		pIn->GetPointClicked(x1, y1);
		cout << "Got Point Clicked." << endl;
		for (int i=0;i<Comp_Count;i++)
		{
			cout << "In for loop number: " << i << endl;
			if (CompList[i]->InsideArea(x1, y1) == true)
			{
				m_SrcComp = CompList[i];
				validSource = 1;
				cout << "Determined Source Gate.";
				break;
			}
		}	
		if (validSource == 0)
		{
			pOut->PrintMsg("INVALID. click on SOURCE GATE.");
		}
		
	}
	int validDst = 0;
	pOut->PrintMsg("ADDING CONNECTION. Click on DESTINATION GATE.");
	while (validDst == 0)
	{
		cout << "In 2nd While Loop";
		pIn->GetPointClicked(x2, y2);
		cout << "Got 2nd Point Clicked.";
		for (int i = 0; i < Comp_Count; i++)
		{
			if (CompList[i]->InsideArea(x2, y2) == true)
			{
				m_DstComp = CompList[i];
				validDst = 1;
				break;
			}
		}
		if (validDst == 0)
		{
			pOut->PrintMsg("INVALID. click on Destination GATE.");
		}
	}
	pOut->ClearStatusBar();
}

void  AddConnection::Execute()
{
	ReadActionParameters();
	GraphicsInfo GInfo;
	GInfo.x1 = m_SrcComp->GetGfxInfo().x2;
	GInfo.x2 = m_DstComp->GetGfxInfo().x1;
	GInfo.y1 = m_SrcComp->GetGfxInfo().y1+(m_SrcComp->GetGfxInfo().y2 - m_SrcComp->GetGfxInfo().y1)/2;
	GInfo.y2 = m_DstComp->GetGfxInfo().y1+((m_DstComp->GetGfxInfo().y2 - m_DstComp->GetGfxInfo().y1) / 3);

	Connection* pA = new Connection(GInfo, NULL ,NULL);
	pManager->AddComponent(pA);

}

void AddConnection ::Undo()
{}

void AddConnection ::Redo()
{}