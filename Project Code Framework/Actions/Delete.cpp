#include"Delete.h"


void Delete::Undo() 
{

}
void Delete::Redo() 
{

}
bool Delete::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Select a component to delete.");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (!pOut->IsDrawingArea(Cx, Cy)) 
	{
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	if (pManager->selectcomponent(Cx, Cy))
	{
		pOut->ClearStatusBar();
		return true;
	}
	else 
	{
		pOut->PrintMsg("Invalid position. Operation was cancelled");
		return false;
	}
	
}
void Delete::Execute()
{
	if (ReadActionParameters())
	{
		mComp = pManager->GetComponent(Cx, Cy);
		
		pApp->RemoveComponent(mComp);
	}
}

Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{

}