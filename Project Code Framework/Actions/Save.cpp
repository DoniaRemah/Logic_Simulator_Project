#include "Save.h"


using namespace std;
Saving::Saving(ApplicationManager* pApp) :Action(pApp)
{

}



bool Saving::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Outputfile.open("Save.txt"); //Opening a text file to write to
	pOut->PrintMsg("Circuit SAVED in Save.txt. Click for a new action. ");
	return true;
}

void Saving::Execute()
{
	//Get Center point of the Gate
	if (ReadActionParameters())
	{
		pManager->Save(Outputfile);
	}
}

void Saving::Undo()
{}

void Saving::Redo()
{}
Saving::~Saving(void)
{
}