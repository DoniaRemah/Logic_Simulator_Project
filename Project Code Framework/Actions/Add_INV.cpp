#include "Add_INV.h"
#include "..\ApplicationManager.h"

Add_INV::Add_INV(ApplicationManager* pApp) :Action(pApp)
{
}

Add_INV::~Add_INV(void)
{
}

void Add_INV::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input INVERTER Gate: Click to add the gate");

	//Wait for User Input
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	int valid = 0;
	int potx1;
	int potx2;
	int poty1;
	int poty2;
	//Wait for User Input
	while (valid == 0)
	{
		pIn->GetPointClicked(Cx, Cy);
		potx1 = Cx - Len / 2;
		potx2 = Cx + Len / 2;
		poty1 = Cy - Wdth / 2;
		poty2 = Cy + Wdth / 2;
		// checking if point within drawing area range.
		if (poty1 > 95)
		{
			valid = 1;
			break;
		}
		else
		{
			pOut->PrintMsg("INVALID POINT.2-Input INVERTER Gate: Click to add the gate");
		}

	}
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Add_INV::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

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

void Add_INV::Undo()
{}

void Add_INV::Redo()
{}
