#include "GUI\Input.h"
#include "GUI\Output.h"


//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output* pOut = new Output();;
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMsg("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Components with all possible states: Normal, highlighted
	//			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMsg("TEST2: Now we will show that Output class can draw any Component in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GraphicsInfo GfxInfo;  //to be used with draw function of the class Ouput

	/// 2.1- AND2 Gate test
	pOut->PrintMsg("Drawing 2-input AND gate, Normal and Highlighted,  Click to continue");
	
	//Drawing Normal AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo);

	//Drawing Highlighted AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.2- NAND2 Gate test
	pOut->PrintMsg("Drawing 2-input NAND gate, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input NAND gate, Normal and Highlighted
	/// NORMAL
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawNAND2(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawNAND2(GfxInfo,true);
	
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.3- OR2 and NOR2 Gates test
	pOut->PrintMsg("Drawing 2-input OR and NOR gates, Normal and Highlighted,  Click to continue");
	
	///TODO: Add code to draw 2-input OR and NOR gates, Normal and Highlighted for each
	//1-2OR
	//NORMAL
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawOR2(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawOR2(GfxInfo, true);


	//2-2NOR
	//NORMAL
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOR2(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOR2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.4- XOR2 and XNOR2 Gates test
	pOut->PrintMsg("Drawing 2-input XOR and XNOR gates, Normal and Highlighted,  Click to continue");
	
	///TODO: Add code to draw 2-input XOR and XNOR gates, Normal and Highlighted for each
	//1-2XOR
	//NORMAL
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawXOR2(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawXOR2(GfxInfo, true);


	//2-2XNOR
	//NORMAL
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawXNOR2(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawXNOR2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();
	

	/// 2.5- Buffer and Inverter Gates test
	pOut->PrintMsg("Drawing Buffer and Inverter Gates, Normal and Highlighted,  Click to continue");
	
	///TODO: Add code to draw Buffer and Inverter Gates, Normal and Highlighted for each
	//1-BUFFER
	//NORMAL
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawBUFFER(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawBUFFER(GfxInfo, true);


	//2-NOT
	//NORMAL
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOT(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOT(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	


	/// 2.6- AND3, NOR3, and XOR3 Gates test
	pOut->PrintMsg("Drawing 3-input AND, NOR, XOR Gates, Normal and Highlighted,  Click to continue");
	
	///TODO: Add code to draw 3-input AND, NOR, and XOR Gates, Normal and Highlighted for each
	//1-3AND
	//NORMAL
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND3(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND3(GfxInfo, true);


	//2-3NOR
	//NORMAL
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOR3(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOR3(GfxInfo, true);

	//3-3XOR
	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawNOR3(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawNOR3(GfxInfo, true);
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	

	/// 2.7- Switch and LED test
	pOut->PrintMsg("Drawing Switch and LED, Normal and Highlighted,  Click to continue");
	
	///TODO: Add code to draw Switch and LED, Normal and Highlighted for each
		//1-SWITCH
	//NORMAL
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawSWITCH(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawSWITCH(GfxInfo, true);


	//2-NOT
	//NORMAL
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawBULB(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawBULB(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();
	


	/// 2.8- Connections
	pOut->PrintMsg("Drawing connections, Normal, Highlighted, straight, and broken,  Click to continue");
	
	///TODO: Add code to draw connections, Normal, Highlighted, straight, and broken (all combinations) 
		//1-STRAIGHT
	//NORMAL
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawConnection_STRAIGHT(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawConnection_STRAIGHT(GfxInfo, true);


	//2-BROKEN
	//NORMAL
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawConnection_BROKEN(GfxInfo);
	//Highlighted
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawConnection_BROKEN(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();
	



	


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->PrintMsg("Testing Input ability to read strings");
	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar and print it inside the drawing area
        string z = pIn->GetSrting(pOut);
	pOut->DrawString(100, 150, z);
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

			do
			{

				ActType = pIn->GetUserAction();

				switch (ActType)
				{
				case ADD_Buff:
					pOut->PrintMsg("Action: add a buffer gate , Click anywhere");
					break;

				case ADD_INV:
					pOut->PrintMsg("Action: add an inverter gate , Click anywhere");
					break;

				case ADD_AND_GATE_2:
					pOut->PrintMsg("Action: add 2-input AND gate , Click anywhere");
					break;
				case ADD_AND_GATE_3:
					pOut->PrintMsg("Action: add 3-input AND gate , Click anywhere");
					break;
				case ADD_NAND_GATE_2:
					pOut->PrintMsg("Action: add 2-input NAND gate , Click anywhere");
					break;

				case ADD_OR_GATE_2:
					pOut->PrintMsg("Action: add 2-input OR gate , Click anywhere");
					break;

				case ADD_NOR_GATE_2:
					pOut->PrintMsg("Action: add 2-input NOR gate , Click anywhere");
					break;
				case ADD_NOR_GATE_3:
					pOut->PrintMsg("Action: add 3-input NOR gate , Click anywhere");
					break;
				case ADD_XOR_GATE_2:
					pOut->PrintMsg("Action: add 2-input XOR gate , Click anywhere");
					break;
				case ADD_XOR_GATE_3:
					pOut->PrintMsg("Action: add 3-input XOR gate , Click anywhere");
					break;
				case ADD_XNOR_GATE_2:
					pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
					break;
				case SAVE:
					pOut->PrintMsg("Action: Saving File, Click Anywhere");
					break;
				case COPY:
					pOut->PrintMsg("Action: Copying , Click Anywhere");
					break;
				case EDIT_Label:
					pOut->PrintMsg("Action: Editing Label , Click Anywhere");
					break;
				case LOAD:
					pOut->PrintMsg("Action: Loading File , Click Anywhere");
					break;
				case PASTE:
					pOut->PrintMsg("Action: Paste , Click Anywhere");
					break;
				case CUT:
					pOut->PrintMsg("Action: Cut , Click Anywhere");
					break;
				case ADD_Label:
					pOut->PrintMsg("Action: Add Label , Click Anywhere");
					break;
				case SELECT:
					pOut->PrintMsg("Action: a click on the Drawing area, Click anywhere");
					break;
				case MULTI_SELECT:
					pOut->PrintMsg("Action: Multi-select , Click Anywhere");
					break;
				case ADD_Switch:
					pOut->PrintMsg("Action: Adding Switch , Click Anywhere");
					break;
				case ADD_CONNECTION:
					pOut->PrintMsg("Action: Adding Wire , Click Anywhere");
					break;
				case ADD_LED:
					pOut->PrintMsg("Action: Adding Led , Click Anywhere");
					break;
				case STATUS_BAR:
					pOut->PrintMsg("Action: a click on the Status Bar, Click anywhere");
					break;

				case DSN_TOOL:
					pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
					break;

				case SIM_MODE:
					pOut->PrintMsg("Action: Switch to Simulation Mode, creating simualtion tool bar");
					pOut->CreateSimulationToolBar();
					do
					{
						ActionType	ActTypeSim = pIn->GetUserAction();
						switch (ActTypeSim)
						{
						case PROB:
							pOut->PrintMsg("Action: Probing, Click anywhere");
							break;
						case VALIDATE:
							pOut->PrintMsg("Action: Validating, Click anywhere");
							break;
						case SIMULATE:
							pOut->PrintMsg("Action: Simulating, Click anywhere");
							break;
						case DSN_MODE:
							pOut->PrintMsg("Action: switching to Design Mode, Click anywhere");
							pOut->CreateDesignToolBar();
							pOut->CreateDesignToolBar2();
							UI.AppMode = DESIGN;
							break;
						case Create_TruthTable:
							pOut->PrintMsg("Action: Creating Truth Table, Click anywhere");
							break;
						}

					} while (UI.AppMode == SIMULATION);

					break;

				case EXIT:
					break;
				}

			} while (ActType != EXIT);

	
	


	/// Exiting
	pOut->PrintMsg("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);

	
	delete pIn;
	delete pOut;	
	return 0;
}


