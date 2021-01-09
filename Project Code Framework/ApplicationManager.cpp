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
#include"Actions/Load.h"
#include "Actions/Cut.h"
#include<fstream>
#include "Actions/AddConnection.h"
#include "Actions/CopyComp.h"
#include "Actions/Paste.h"
#include "Components/LED.h"
#include "Components/SWITCH.h"
#include "Actions/ChangeSwitch.h"
#include "Actions/SimulateCirc.h"

ApplicationManager::ApplicationManager()
{
	ClipBoard = NULL;
	CompCount = 0;
	DidSwitch = false;
	for (int i = 0; i < MaxCompCount; i++)
	{
		CompList[i] = NULL;
		ConnList[i] = NULL;
	}
		
	mSwitch = NULL;
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;	

}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction(int* x, int* y)
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(x, y);
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
		case LOAD:
			pAct = new Loading(this); //Loading from a text file
		case CUT:  
			pAct = new CutComp(this);
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
		case COPY:
			pAct = new Copy(this);
			DidSwitch = false;
			break;
		case PASTE:
			pAct = new Paste(this);
			DidSwitch = false;
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
			OutputInterface->PrintMsg("Simulating Circuit...");
			bool InSim = true; // Boolean to be able to Select and Unselect Icon Simulate.
			do // Stay in While Loop Untill Switch to Design Mode or Clicking Simulate Icon. 
			{
				pAct = new Simulate(this);	
				if (pAct)
				{
					pAct->Execute();
					delete pAct;
					pAct = NULL;
					UpdateInterface();
				}
				int x=0,y=0;
				ActType = GetUserAction(&x ,& y);
				Action* pAct2 = NULL; // Getting Action While Simulating.
				switch (ActType)
				{
				case Change_Switch: // User Changing Switch Output
					pAct2 = new ChangeSwitch(this,x,y);
					DidSwitch = false;
					break;
				case DSN_MODE: // USer Wants to switch to design Mode (Break out of Loop).
					UI.AppMode = DESIGN;
					InSim = false;
					DidSwitch = true;
					break;
				case SIMULATE: // User Clicked on Simulate.(Break out of Loop)
					InSim = false;
					DidSwitch = false;
					break;
				}
				if (pAct2)
				{
					pAct2->Execute();
					delete pAct2;
					pAct2 = NULL;
					UpdateInterface();
				}
				
			} while (InSim == true );
			OutputInterface->ClearStatusBar();
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
		OutputInterface->ClearDrawingArea();
		for(int i=0; i<CompCount; i++)
			if(CompList[i]!= NULL)
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
		Connection* mConn = dynamic_cast <Connection*>(CompList[i]);
		if (mConn == NULL)
		{
			if (CompList[i]->InsideArea(x, y))
			{
				return true;
			}
		}
		else
		{
			if (mConn->InsideArea(x, y))
			{
				return true;
			}
		}
	}
	return false; 
}

void ApplicationManager::RemoveComponent(Component* pComp)
{
	int ConCount = 0;
	Connection** ConnList = CheckConnection(ConCount);
	// First Loop: Checks on Component.
	for (int i = 0; i < CompCount;i++)
	{
		if (pComp == CompList[i])
		{
			// Checks On Connection associated with component.
			for (int Q=0; Q<ConCount;Q++) // Loop with Number of Connections.
			{
				if ((ConnList[Q]->GetDstComponent() == pComp) || (ConnList[Q]->GetSourceComponent() == pComp) || ConnList[Q] == pComp)
				{
					Gate* mGate1 = dynamic_cast<Gate*>(ConnList[Q]->GetDstComponent());
					Gate* mGate2 = dynamic_cast<Gate*>(ConnList[Q]->GetSourceComponent());
					// Unconnecting Input Pin of Destination Component (Gate or Led)
					if (mGate1 == NULL)
					{
						LED* mLed = dynamic_cast<LED*>((ConnList[Q]->GetDstComponent()));
						mLed->UnConnectInputPin();
					}
					else
					{
						mGate1->UnConnectInputPin(ConnList[Q]->GetDstPinNumber());
					}

					// Unconnecting Output Pin of Source Component (Gate or Switch)
					if (mGate2 == NULL)
					{
						SWITCH* mSwitch = dynamic_cast<SWITCH*>((ConnList[Q]->GetSourceComponent()));
						mSwitch->UnConnectOuputPin(ConnList[Q]);
					}
					else
					{
						mGate2->UnConnectOuputPin(ConnList[Q]);
					}
					if (ConnList[Q] != pComp)
					{	
						// Loop that Deletes Connections.
						for (int j = 0; j < CompCount; j++)
						{

							// Deleting Connection from Component List	
							if (ConnList[Q] == CompList[j])
							{

								if (j == CompCount - 1)
								{
									CompList[j] = NULL; CompCount--;
								}

								else
								{
									CompList[j] = CompList[CompCount - 1];
									CompList[CompCount - 1] = NULL;
									CompCount--;
								}
							}

						}

					}
				}
			}
			// Deleting Component (Gate,Led,Switch)
			if (i == CompCount - 1) 
			{ 
				CompList[i] = NULL; CompCount--; 
			}
			
			else
			{
				CompList[i] = CompList[CompCount - 1];
				CompList[CompCount-1] = NULL;
				CompCount--;
			}
		}
		
	}

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
				CompList[i]->SetID(i); //Setting a unique ID for each component
				CompList[i]->Save(Outputfile);  //Writing component(GATES, LEDS, AND SWITCHES) info to the text file	
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
	Outputfile.close(); //Closing the file
}

void ApplicationManager::Load(ifstream& Inputfile) //Reading a circuit from a text file
{
	DeleteEverything();
	CompCount = 0;
	int count = 0;
	Inputfile >> count; //Count of all components (EXCEPT CONNECTIONS)
	for (int i = 0; i < count; i++)
	{
		string type; //Component type
		Inputfile >> type;
		Component* pc; //Component pointer to construct the component in the drawing area
		if (type == "AND2")
			pc = new AND2(AND2_FANOUT);
		else if (type == "LED")
			pc = new LED(AND2_FANOUT);
		else if (type == "SWITCH")
			pc = new SWITCH(AND2_FANOUT);
		else if (type == "AND3")
			pc = new AND3(AND2_FANOUT);
		else if (type == "BUFF")
			pc = new BUFF(AND2_FANOUT);
		else if (type == "NOT")
			pc = new INV(AND2_FANOUT);
		else if (type == "NAND2")
			pc = new NAND2(AND2_FANOUT);
		else if (type == "OR2")
			pc = new OR2(AND2_FANOUT);
		else if (type == "NOR2")
			pc = new NOR2(AND2_FANOUT);
		else if (type == "NOR3")
			pc = new NOR3(AND2_FANOUT);
		else if (type == "XNOR2")
			pc = new XNOR2(AND2_FANOUT);
		else if (type == "XOR2")
			pc = new XOR2(AND2_FANOUT);
		else 
			pc = new XOR3(AND2_FANOUT);

		pc->Load(Inputfile);
		AddComponent(pc); //Adding the component to the component 
	}
	//Reading the rest of the circuit data (in order of the file format)
		string Text;
		Inputfile >> Text;
		int SourceID;
		int DestID;
		int pinNum;
		Inputfile >> SourceID;
		Inputfile >> DestID;
		Inputfile >> pinNum;

		while (SourceID != -1) //Meaning the end of the text file(-1)
		{
			GraphicsInfo gfxConnection;

			Component* pSource =FindComponent(SourceID);

			GraphicsInfo gfxSource = pSource->GetGfxInfo(); //Coordinates of Source Component
			 //Estimation of the starting point of the connection
			gfxConnection.x1 = gfxSource.x1 + UI.AND2_Width - 3;
			gfxConnection.y1 = gfxSource.y1 + 25;

			Component* pDst = FindComponent(DestID);

			int xDst;
			int yDest;
			pDst->GetinputPinCoordinates(pinNum, xDst, yDest); //Getting coordinates of input pins of the destination component
			//End point of connection
			gfxConnection.x2 = xDst;
			gfxConnection.y2 = yDest;


			OutputPin* pinSource = pSource->GetOutPin();
			InputPin* pinDest = pDst->GetInPin(pinNum);
			Connection* pConn = new Connection(gfxConnection, pinSource, pinDest,pSource,pDst);
			pinDest->SetConnection(pConn);
			pinDest->SetConnectionStat(true);
			pinSource->ConnectTo(pConn);
			pSource->SetNextComp(pConn);
			pConn->SetNextComp(pDst);
			AddComponent(pConn);
			Inputfile >> SourceID;
			Inputfile >> DestID;
			Inputfile >> pinNum;
		}
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
	{
		delete CompList[i];
	}
		
	delete OutputInterface;
	delete InputInterface;

}

Component** ApplicationManager::GetCompList(int& N)
{
	N = CompCount;
	return CompList;
}

Connection** ApplicationManager::CheckConnection(int& ConC)
{
	for (int k = 0; k < CompCount; k++)
	{
		Connection* mConnection = dynamic_cast <Connection*> (CompList[k]);
		if (mConnection != NULL)
		{
			ConnList[ConC] = mConnection;
			ConC++;
		}
	}
	return ConnList;
}

void ApplicationManager::DeleteEverything()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];

}


void ApplicationManager::CutComponent(Component* Cut_Comp)
{
	ClipBoard = Cut_Comp;
	UnConnectInputPin(ClipBoard);
	UnConnectOutputPin(ClipBoard);
	RemoveComponent(Cut_Comp);
}

void ApplicationManager::CopyComponent(Component* Copy_Comp)
{
	ClipBoard = Copy_Comp;
	GraphicsInfo gfx;
	gfx.x1 = 0; gfx.x2 = 0; gfx.y1 = 0; gfx.y2 = 0;
	// Determnining Type of Component to Create new Instance of it.
	AND2* and2g = dynamic_cast <AND2*>(ClipBoard);
	if (and2g != NULL)
	{
		ClipBoard = new AND2(gfx, 5);
	}
	else
	{
		AND3* and3g = dynamic_cast <AND3*>(ClipBoard);
		if (and3g != NULL)
		{
			ClipBoard = new AND3(gfx, 5);
		}
		else
		{
			BUFF* bufg = dynamic_cast <BUFF*>(ClipBoard);
			if (bufg != NULL)
			{
				ClipBoard = new BUFF(gfx, 5);
			}
			else
			{
				INV* invg = dynamic_cast <INV*>(ClipBoard);
				if (invg != NULL)
				{
					ClipBoard = new INV(gfx, 5);
				}
				else
				{
					LED* led = dynamic_cast <LED*>(ClipBoard);
					if (led != NULL)
					{
						ClipBoard = new LED(gfx);
					}
					else
					{
						NAND2* nand2g = dynamic_cast <NAND2*>(ClipBoard);
						if(nand2g !=NULL)
						{
							ClipBoard = new NAND2(gfx, 5);
						}
						else
						{
							NOR2* nor2g = dynamic_cast <NOR2*>(ClipBoard);
							if (nor2g != NULL)
							{
								ClipBoard = new NOR2(gfx, 5);
							}
							else
							{
								NOR3* nor3g = dynamic_cast <NOR3*>(ClipBoard);
								if (nor3g != NULL)
								{
									ClipBoard = new NOR3(gfx, 5);
								}
								else
								{
									OR2* or2g = dynamic_cast <OR2*>(ClipBoard);
									if (or2g != NULL)
									{
										ClipBoard = new OR2(gfx, 5);
									}
									else
									{
										SWITCH* switchc = dynamic_cast <SWITCH*>(ClipBoard);
										if (switchc != NULL)
										{
											ClipBoard = new SWITCH(gfx, 5);
										}
										else
										{
											XNOR2* xnor2g = dynamic_cast <XNOR2*>(ClipBoard);
											if (xnor2g != NULL)
											{
												ClipBoard = new XNOR2(gfx, 5);
											}
											else
											{
												XOR2* xor2 = dynamic_cast <XOR2*>(ClipBoard);
												if (xor2 != NULL)
												{
													ClipBoard = new XOR2(gfx, 5);
												}
												else
												{
													XOR3* xor3 = dynamic_cast <XOR3*>(ClipBoard);
													ClipBoard = new XOR3(gfx, 5);

												}


											}


										}

									}
								}
							}
						}
					}
				}

			}

		}
	}

}

void ApplicationManager::PasteComponent(GraphicsInfo GInfo)
{
	ClipBoard->SetGfxInfo(GInfo);
	AddComponent(ClipBoard);
}

void ApplicationManager:: UnConnectOutputPin(Component* Comp)
{
	int ConNum = 0;
	Connection** ConnList = CheckConnection(ConNum); // Getting List of Connections.
	// UnConnecting Pins.
	Gate* mGate = dynamic_cast <Gate*> (Comp); // Determining Component Type.
	if (mGate == NULL)
	{
		SWITCH* Switch = dynamic_cast <SWITCH*> (Comp);
		if (Switch != NULL)
		{
			for (int x = 0; x < ConNum; x++)
			{
				if (Switch == ConnList[x]->GetSourceComponent())
				{
					Switch->UnConnectOuputPin(ConnList[x]);
				}
			}
		}
	
	}
	else
	{

		for (int x = 0; x < ConNum; x++)
		{
			if (mGate == ConnList[x]->GetSourceComponent())
			{
				mGate->UnConnectOuputPin(ConnList[x]);
			}
		}
	}
}

void ApplicationManager :: UnConnectInputPin(Component* Comp)
{

	Gate* mGate = dynamic_cast <Gate*> (Comp); // Determining Component Type.
	if (mGate == NULL)
	{
		LED* Led = dynamic_cast <LED*> (Comp);
		if (Led != NULL)
		{
			Led->UnConnectInputPin();
		}		
		
	}
	else
	{
		for (int i = 0; i < mGate->GetNoInputPins(); i++)
		{
			mGate->UnConnectInputPin(i);
		}

	}
}


bool ApplicationManager::CheckSwitch(int x,int y)
{
	Component* mComp = GetComponent(x, y);
	mSwitch = dynamic_cast<SWITCH*> (mComp);
	if (mSwitch != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ApplicationManager:: ChangeSwitchF()
{
	if (mSwitch != NULL)
	{
		mSwitch->Operate();
	}
}

void ApplicationManager::SimulateCircuit()
{
	// Getting List of Components
	int ConCount = 0;
	Connection** myCOnn = CheckConnection(ConCount);
	for (int i = 0; i < ConCount; i++) // A Loop that Operates Connections and Gates 
	{ 
		Component* myDstGate = myCOnn[i]->GetDstComponent();
		Component* mySrcGate = myCOnn[i]->GetSourceComponent();
		LED* mled = dynamic_cast <LED*>(myDstGate);
		if (mled == NULL)
		{
			SWITCH* Switch = dynamic_cast <SWITCH*> (mySrcGate);
			if (Switch == NULL)
			{
				mySrcGate->Operate(); // First Operate the Source Gate of Component: Calculate Output Pin Status (If not Led or Switch)
			}
		}
		myCOnn[i]->Operate(); // Then Operate the Connection (Sets input pin status of Dst Gate)
		myDstGate->Operate(); // Then Operate the Destinarion Gate.
	}
}

