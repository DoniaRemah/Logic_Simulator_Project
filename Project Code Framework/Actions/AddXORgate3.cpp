#include "AddXORgate3.h"
#include "..\ApplicationManager.h"

AddXORgate3::AddXORgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddXORgate3::~AddXORgate3(void)
{
}

bool AddXORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input XOR Gate: Click to add the gate");

	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
	return true;
}

void AddXORgate3::Execute()
{
	
	//Get Center point of the Gate
	bool x =ReadActionParameters();

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
		XOR3* pA = new XOR3(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddXORgate3::Undo()
{}

void AddXORgate3::Redo()
{}


