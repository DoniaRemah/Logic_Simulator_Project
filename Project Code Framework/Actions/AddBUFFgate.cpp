#include "AddBUFFgate.h"
#include "..\ApplicationManager.h"

AddBUFFgate::AddBUFFgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddBUFFgate::~AddBUFFgate(void)
{
}

void AddBUFFgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input BUFF Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBUFFgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.BUFFER_Width;
	int Wdth = UI.BUFFER_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	BUFF* pA = new BUFF(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddBUFFgate::Undo()
{}

void AddBUFFgate::Redo()
{}
