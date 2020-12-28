#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");
	// Setting Potential Parameters.
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	int validBar = 0;
	int validComp = 0;
	int potx1;
	int potx2;
	int poty1;
	int poty2;
	//Validating Point Clicked.
	while (validBar == 0 && validComp == 0)
	{
		pIn->GetPointClicked(Cx, Cy);
		potx1 = Cx - Len / 2;
		potx2 = Cx + Len / 2;
		poty1 = Cy - Wdth / 2;
		poty2 = Cy + Wdth / 2;
		// checking if point within drawing area range.
		if (poty1 > 95)
		{
			validBar = 1;
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

void AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	AND2 *pA=new AND2(GInfo, AND2_FANOUT); 
	pManager->AddComponent(pA);
}

void AddANDgate2::Undo()
{}

void AddANDgate2::Redo()
{}

