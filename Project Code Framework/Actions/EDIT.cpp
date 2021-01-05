#include "EDIT.h"
#include "..\ApplicationManager.h"

EDIT::EDIT(ApplicationManager* pApp) :Action(pApp)
{
}

EDIT::~EDIT(void)
{
}

bool EDIT::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Edit the label of component:select the component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	if (pManager->selectcomponent(Cx, Cy))
	{
		mComp = pManager->GetComponent(Cx, Cy);
		privlabel = mComp->GetLabel();
		if (!privlabel.empty())
		{
			Editlabel = pIn->GetSrting(pOut,"Edit the component Label:",privlabel);
			return true;
		}
		else
		{
			pOut->PrintMsg("please put the label first then edit it ");
			return false;
		}
	}
	else
	{
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
}
	
	

void EDIT::Execute()
{
	Output* pOut = pManager->GetOutput();
	//Get Center point of the Gate
	bool x=ReadActionParameters();
	if (x)
	{
		GraphicsInfo GInfo = mComp->GetGfxInfo();//Gfx info to be used to construct the EDIT
		pOut->Cleartextindrawingarea(GInfo.x1, (GInfo.y1 - 20));
		pOut->DrawString(GInfo.x1, GInfo.y1 - 20, Editlabel);
	}
}

void EDIT::Undo()
{}

void EDIT::Redo()
{}

