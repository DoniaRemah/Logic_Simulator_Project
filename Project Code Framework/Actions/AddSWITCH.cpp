#include "AddSWITCH.h"
#include "..\ApplicationManager.h"

AddSWITCH::AddSWITCH(ApplicationManager * pApp) :Action(pApp)
{
}

AddSWITCH::~AddSWITCH(void)
{
}

bool AddSWITCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Click to add the SWITCH");
	pIn->GetPointClicked(Cx, Cy);

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy)) {
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
	return true;
}

void AddSWITCH::Execute()
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
		SWITCH* pA = new SWITCH(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddSWITCH::Undo()
{}

void AddSWITCH::Redo()
{}
