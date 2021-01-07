#include "Save.h"


using namespace std;
Saving::Saving(ApplicationManager* pApp) :Action(pApp)
{

}



bool Saving::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Outputfile.open("Save.txt");

	pOut->ClearStatusBar();
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