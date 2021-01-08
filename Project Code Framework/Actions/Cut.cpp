#include "Cut.h"
#include "..\ApplicationManager.h"
CutComp::CutComp(ApplicationManager* pApp) :Action(pApp)
{
	mComp == NULL;
	Cx = 0; Cy = 0;
}

bool CutComp::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("PLEASE SELECT A COMPONENT TO CUT.");
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy))
	{
		pOut->PrintMsg("Invalid Area. Operation Cancelled.");
		return false;
	}
	else
	{
		
		if (pManager->selectcomponent(Cx, Cy))
		{
			pOut->PrintMsg("Component Cut. Please Click on Paste Icon.");
			return true;
		}
		else
		{
			pOut->PrintMsg("Invalid Position. Did Not Click on Component. Operation Cancelled.");
			return false;
		}
	}
}

void CutComp::Execute()
{
	bool ValidParameters = ReadActionParameters();
	if (ValidParameters)
	{
		mComp = pManager->GetComponent(Cx, Cy);
		pManager->CutComponent(mComp);
	}
}

void CutComp::Undo()
{

}

void CutComp::Redo()
{

}

CutComp:: ~CutComp()
{

}