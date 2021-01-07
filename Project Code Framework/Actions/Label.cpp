#include "Label.h"
#include "..\ApplicationManager.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
}

Label::~Label(void)
{
}

bool Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Please select a component to put label ");
	pIn->GetPointClicked(Cx, Cy);//Wait for User Input

	pOut->ClearStatusBar();
	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	// check if this area is empty or not 
	if (pManager->selectcomponent(Cx, Cy))
	{
		mComp = pManager->GetComponent(Cx, Cy);
		newlabel = pIn->GetSrting(pOut, "Enter the label of component:",newlabel);
		return true;
	}
	else
	{
		pOut->PrintMsg("Invalid position,Operation was cancelled");
		return false;
	}
}

void Label::Execute()
{
	Output* pOut = pManager->GetOutput();
	GraphicsInfo GInfo;
	//Get Center point of the Gate
	bool x=ReadActionParameters();
	if (x)
	{
		GInfo=mComp->GetGfxInfo();
		mComp->SetLabel(newlabel);
	}
}

void Label::Undo()
{}

void Label::Redo()
{}
