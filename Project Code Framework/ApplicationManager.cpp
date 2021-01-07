#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddBUFFgate.h"
#include "Actions\AddANDgate3.h"
#include "Actions\Add_INV.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXORgate3.h"
#include "Actions\Addled.h"
#include "Actions\AddSWITCH.h"
#include "Actions\EDIT.h"
#include "Actions\Label.h"
#include"Actions/Delete.h"
#include"Actions/Select.h"
#include"Actions/Save.h"

#include <iostream>
#include<fstream>
#include "Actions/AddConnection.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	DidSwitch = false;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;	
	cout << "New Component Added: " << CompCount << endl;

}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	if (UI.AppMode == DESIGN)
	{
		
		Action* pAct = NULL;
		switch (ActType)
		{
		case ADD_AND_GATE_2:
			pAct = new AddANDgate2(this);
			DidSwitch = false;
			break;
		case ADD_Buff:
			pAct = new AddBUFFgate(this);
			DidSwitch = false;
			break;                  //Add 1-input Buffer gate
		case ADD_INV:
			pAct = new Add_INV(this);
			DidSwitch = false;
			break;                    //Add 1-input Inverter gate
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			DidSwitch = false;
			break;                    //Add 2-input OR gate
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			DidSwitch = false;
			break;                   //Add 2-input NAND gate
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			DidSwitch = false;
			break;                   //Add 2-input NOR gate
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			DidSwitch = false;
			break;                   //Add 2-input XOR gate
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			DidSwitch = false;
			break;                  //Add 2-input XNOR gate
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			DidSwitch = false;
			break;                    //Add 3-input AND gate
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			DidSwitch = false;
			break;                     //Add 3-input NOR gate
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			DidSwitch = false;
			break;                     //Add 3-input XOR gate
			
		case ADD_Switch:
			pAct = new AddSWITCH(this);
			DidSwitch = false;
			break;			            //Add Switch
			
		case ADD_LED:
			pAct = new Addled(this);
			DidSwitch = false;//Add LED
			break;
		case EDIT_Label:
			pAct = new EDIT(this);
			DidSwitch = false;
			break;
		case ADD_Label:
			pAct = new Label(this);
			DidSwitch = false;
			break;                        //EDIT
		case Action_SELECT:
			pAct = new Select(this);
			DidSwitch = false;
			break;
		case SAVE: //Saving to a text file
			pAct = new Saving(this); 
			DidSwitch = false;
			break; 
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			DidSwitch = false;
			break;
		case SIM_MODE:
			UI.AppMode = SIMULATION;
			DidSwitch = true;
			break;
		case EXIT:
			break;
		case Action_DELETE:
			DidSwitch = false;
			pAct = new Delete(this);
			break;
		
		}
		if (pAct)
		{
			pAct->Execute();
			delete pAct;
			pAct = NULL;
		}
	}
	else
	{
		Action* pAct = NULL;
		switch (ActType)
		{
		case DSN_MODE:
			UI.AppMode = DESIGN;
			DidSwitch = true;
			break;
		case SIMULATE:

			break;
		}
		
		if (pAct)
		{
			pAct->Execute();
			delete pAct;
			pAct = NULL;
		}
		
	}
	
	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	if (UI.AppMode == SIMULATION && DidSwitch == true)
	{
		OutputInterface->CreateSimulationToolBar();
	}
	else if (UI.AppMode == DESIGN && DidSwitch == true)
	{
		OutputInterface->CreateDesignToolBar();
		OutputInterface->CreateDesignToolBar2();
	}
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}
Component*ApplicationManager::GetComponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->InsideArea(x,y))
		{
			return CompList[i];
		}
	}
	return NULL;
}
bool ApplicationManager::selectcomponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->InsideArea(x, y))
		{
			return true;
		}
	}
	return false;
}

bool ApplicationManager::RemoveComponent(Component* pComp)
{
	for (int i = 0; i < CompCount;i++)
	{
		if (pComp == CompList[i])
		{
			if (i == CompCount - 1) 
			{ 
				CompList[i] = NULL; CompCount--; 
				cout << "Component Deleted, Component count is: " << CompCount << endl;
				return true;
			}
			
			else 
			{
				CompList[i] == CompList[CompCount-1];
				CompList[CompCount-1] == NULL;
				CompCount--;
				cout << "Component Deleted, Component count is: " << CompCount << endl;
				return true;
			}
		}
		
	}
	return false;
}
void ApplicationManager::Save(ofstream & Outputfile)
{
	int count = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (!dynamic_cast<Connection*>(CompList[i])) //Counting Components (Minus Connections)
		{
			count++;
		}
	}
	Outputfile << count << endl; //Writing the number of components to the text file
	for (int i = 0; i < CompCount; i++)
	{
		if (!dynamic_cast<Connection*>(CompList[i])) //Counting Components (Minus Connections)
		{
			CompList[i]->SetID(i);
			CompList[i]->Save(Outputfile);
			
			//Writing component(GATES, LEDS, AND SWITCHES) info to the text file
		}
		
	}
	 // Connections
	Outputfile << "Connections:" << endl;
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Connection*>(CompList[i]))
		{
			CompList[i]->Save(Outputfile); //Writing CONNECTION info to the text file
		}
	}
	Outputfile << "-1"; //Flag that the file ended
	Outputfile.close(); //Closing thr file
}
Component* ApplicationManager::FindComponent(int ID)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetID() == ID)          //Finding a component from its ID
			return CompList[i];
	}
	return NULL;
}


////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;

}

Component** ApplicationManager::GetCompList(int& N)
{
	N = CompCount;
	return CompList;
}
