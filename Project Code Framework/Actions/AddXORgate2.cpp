#include "AddXORgate2.h"
#include "..\ApplicationManager.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

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
			pOut->PrintMsg("INVALID POINT. 2-Input AND Gate: Click to add the gate");
		}

	}

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.XOR2_Width;
	int Wdth = UI.XOR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XOR2* pA = new XOR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddXORgate2::Undo()
{}

void AddXORgate2::Redo()
{}


