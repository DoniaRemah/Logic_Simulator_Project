#include "AddBUFFgate.h"
#include "..\ApplicationManager.h"

AddBUFFgate::AddBUFFgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddBUFFgate::~AddBUFFgate(void)
{
}

bool AddBUFFgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input BUFF Gate: Click to add the gate");

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

void AddBUFFgate::Execute()
{
	//Get Center point of the Gate
	

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
		BUFF* pA = new BUFF(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddBUFFgate::Undo()
{}

void AddBUFFgate::Redo()
{}
