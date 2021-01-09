#include "Add_INV.h"
#include "..\ApplicationManager.h"

Add_INV::Add_INV(ApplicationManager* pApp) :Action(pApp)
{
	Cx = 0; Cy = 0;
}

Add_INV::~Add_INV(void)
{
}

bool Add_INV::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input INVERTER Gate: Click to add the gate");

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

void Add_INV::Execute()
{
	bool x = ReadActionParameters();
	//Get Center point of the Gate
	if (x)//check if the click in drawing area or not
	{
		//Calculate the rectangle Corners
		int Len = UI.NOT_Width;
		int Wdth = UI.NOT_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		INV* pA = new INV(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	
}

void Add_INV::Undo()
{}

void Add_INV::Redo()
{}
