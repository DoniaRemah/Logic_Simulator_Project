#include "Addled.h"
#include "..\ApplicationManager.h"

Addled::Addled(ApplicationManager * pApp) :Action(pApp)
{
}

Addled::~Addled(void)
{
}

void Addled::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Click to add the LED");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Addled::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.BULB_Width;
	int Wdth = UI.BULB_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	LED* pA = new LED(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void Addled::Undo()
{}

void Addled::Redo()
{}
