#include "Load.h"
#include "..\ApplicationManager.h"
#include<iostream>
#include<fstream>
Loading::Loading(ApplicationManager* pApp) :Action(pApp)
{
}

Loading::~Loading(void)
{
}

bool Loading::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Inputfile.open("Load.txt");
	pOut->PrintMsg("Loading circuit from file.");
	pOut->ClearStatusBar();
	return true;
}

void Loading::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	pManager->Load(Inputfile);

}

void Loading::Undo()
{}

void Loading::Redo()
{}