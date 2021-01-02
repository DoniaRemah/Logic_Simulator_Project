#include "Addled.h"
#include "..\ApplicationManager.h"

Addled::Addled(ApplicationManager * pApp) :Action(pApp)
{
}

Addled::~Addled(void)
{
}

bool Addled::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Click to add the LED");

	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
	return true;
}

void Addled::Execute()
{
	bool x = ReadActionParameters();
	//Get Center point of the Gate
	if (x)     //check if the click in drawing area or not
	{
		//Calculate the rectangle Corners
		int Len = UI.BULB_Width;
		int Wdth = UI.BULB_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the LED

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		LED* pA = new LED(GInfo);
		pManager->AddComponent(pA);
	}
}

void Addled::Undo()
{}

void Addled::Redo()
{}

int Addled::GetInputPinStatus()
{
	return -1;
}
