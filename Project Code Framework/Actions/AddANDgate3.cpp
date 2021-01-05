#include "AddANDgate3.h"
#include "..\ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddANDgate3::~AddANDgate3(void)
{
}

bool AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

	//Wait for User Input
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	if (pManager->selectcomponent(Cx, Cy))
	{
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	else
	{
		pOut->ClearStatusBar();
		return true;
	}

}

void AddANDgate3::Execute()
{
	//Get Center point of the Gate
	

	bool x = ReadActionParameters();
	//Get Center point of the Gate
	if (x )//check if the click in drawing area or not
	{
		//Calculate the rectangle Corners
		int Len = UI.NOT_Width;
		int Wdth = UI.NOT_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		AND3* pA = new AND3(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddANDgate3::Undo()
{}

void AddANDgate3::Redo()
{}


