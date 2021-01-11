#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components/Connection.h"
#include "Components/SWITCH.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCompCount = 200 };	//Max no of Components	
	bool DidSwitch;
	Component* ClipBoard;
private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	SWITCH* mSwitch;
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Connection* ConnList[MaxCompCount]; // List of Connections
	bool ValidCircuit;
public:
public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction(int* x = 0, int* y = 0);
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);

	Component ** GetCompList(int& N); // Getter for Component List.

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	Connection** CheckConnection(int& ConC); // Function that makes list of Connections and their number.

	void AddComponent(Component* pComp); // Adds Component to List

	void RemoveComponent(Component* pComp); // Deletes Component from List

	Component* GetComponent(int x, int y);	// Get Component from a Point Clicked inside it's area.

	bool selectcomponent(int x, int y); // Checks if Point clicked is inside a component
	void UnConnectOutputPin(Component * Comp); // Unconnects all Connections from Output Pin
	void UnConnectInputPin(Component* Comp); // UnConnects all input pins of Component
	//To save in a text file
	void Save(ofstream& Output);
	Component* FindComponent(int ID);

	void CutComponent(Component * Cut_Comp); // Adds Cut Component to ClipBoard and Deletes the previous one.

	void CopyComponent(Component* Copy_Comp); // Adds Coppied Component o Clipbard.

	void PasteComponent(GraphicsInfo GInfo); // Draws Component and adds it to CompList.

	bool CheckSwitch(int x, int y); // Checks if Point Clicked is a switch.

	void ChangeSwitchF(); // Changes State of Switch

	void SimulateCircuit(); // Simulates

	bool ValidateCircuit();

	bool ProbingCircuit(int x, int y, bool& Status);
	~ApplicationManager(); //destructor
};

#endif
