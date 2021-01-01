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
	pOut->PrintMsg("Edit the label of component: ");
	
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();
	return true;
}

void EDIT::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	

	GraphicsInfo GInfo; //Gfx info to be used to construct the EDIT
	
}

void EDIT::Undo()
{}

void EDIT::Redo()
{}


