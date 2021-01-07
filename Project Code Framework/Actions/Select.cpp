#include"Select.h"
Select::Select(ApplicationManager* pApp) : Action(pApp) {

}
bool Select::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Select or Unselect a component.");

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
void Select::Execute()
{
	if (ReadActionParameters())
	{
		mComp = pManager->GetComponent(Cx, Cy);
	   
		Gate* mGate = dynamic_cast<Gate*>(mComp);
		if (mGate == NULL)
		{
			SWITCH* mSwitch = dynamic_cast<SWITCH*>(mComp);
			if (mSwitch == NULL)
			{
				LED* mLed = dynamic_cast<LED*>(mComp);
				if (mLed == NULL)
				{
					Connection* mConnection = dynamic_cast<Connection*>(mComp);
					if (mConnection->GetIsSelected() == false)
					{
						mConnection->SetIsSelected(true);
						mConnection->Draw(pManager->GetOutput());
					}
					else
					{
						mConnection->SetIsSelected(false);
						mConnection->Draw(pManager->GetOutput());
					}
				}
				else
				{
					if (mLed->GetIsSelected() == false)
					{
						mLed->SetIsSelected(true);
						mLed->Draw(pManager->GetOutput());
					}
					else
					{
						mLed->SetIsSelected(false);
						mLed->Draw(pManager->GetOutput());
					}
				}
			}

			else
			{
				if (mSwitch->GetIsSelected() == false)
				{
					mSwitch->SetIsSelected(true);
					mSwitch->Draw(pManager->GetOutput());
				}
				else
				{
					mSwitch->SetIsSelected(false);
					mSwitch->Draw(pManager->GetOutput());
				}
			}
		}
		else
		{
			if (mGate->GetIsSelected() == false)
			{


				mGate->SetIsSelected(true);
				mGate->Draw(pManager->GetOutput());
			}
			else
			{
				mGate->SetIsSelected(false);
				mGate->Draw(pManager->GetOutput());
			}
		}
		
	}
}

void Select::Undo() {

}
void Select::Redo() {

}
Select::~Select(void) {

}