#include "Paste.h"
#include "..\ApplicationManager.h"
Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
	Cx = 0; Cy = 0;
}

bool Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("PASTING, CLICK ANYWHERE.");
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy))
	{
		pOut->PrintMsg("Invalid Area. Operation Cancelled.");
		return false;
	}
	else
	{

		if (pManager->selectcomponent(Cx, Cy))
		{
			pOut->PrintMsg("Invalid Area. Component Already in Place.");
			return false;
		}
		else
		{
			pOut->PrintMsg("Component Pasted.Click on Next Action.");
			return true;
		}
	}
}

void Paste::Execute()
{
	bool ValidParameters = ReadActionParameters();
	if (ValidParameters)
	{
		GraphicsInfo GInfo;
		GInfo.x1 = Cx - 50 / 2;
		GInfo.x2 = Cx + 50 / 2;
		GInfo.y1 = Cy - 50 / 2;
		GInfo.y2 = Cy + 50 / 2;
		pManager->PasteComponent(GInfo);
	}
}

void Paste::Undo()
{

}

void Paste::Redo()
{

}

Paste:: ~Paste()
{

}