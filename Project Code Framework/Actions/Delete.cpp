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
		return false;
	}
	
}
void Delete::Execute()
{
	if (ReadActionParameters())
	{
		mComp = pManager->GetComponent(Cx, Cy);
		Connection* mConnection = dynamic_cast<Connection*>(mComp);
		if (mConnection == NULL)
		{
			mComp->DeleteComp(pManager->GetOutput(), mComp->GetGfxInfo()); //Function in Component 
		}
		else
		{
			//mConnection->DeleteComp(pManager->GetOutput(), mComp->GetGfxInfo());
		}
		
		pManager->RemoveComponent(mComp);
	}
	
}

Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{

}