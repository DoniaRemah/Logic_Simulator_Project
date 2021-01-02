#include "AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

bool AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
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
		OR2* pA = new OR2(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddORgate2::Undo()
{}

void AddORgate2::Redo()
{}