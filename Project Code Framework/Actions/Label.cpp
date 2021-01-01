#include "Label.h"
#include "..\ApplicationManager.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
	mComp = NULL;
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
	pOut->PrintMsg("Please select a component ");
	pIn->GetPointClicked(Cx, Cy);//Wait for User Input
	pOut->ClearStatusBar();

	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	if (mComp == NULL) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
	return true;
}

void Label::Execute()
{
	//Get Center point of the Gate
	bool x=ReadActionParameters();
	if (x)
	{



	}
	//Calculate the rectangle Corners


	GraphicsInfo GInfo; //Gfx info to be used to construct the EDIT

}

void Label::Undo()
{}

void Label::Redo()
{}
