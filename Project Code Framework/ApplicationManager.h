#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components/Connection.h"
#include "Components/LED.h"
#include "Components/SWITCH.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCompCount = 200 };	//Max no of Components	
	bool DidSwitch;
private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Connection* ConnList[MaxCompCount]; // List of Connections

public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	Component ** GetCompList(int& N);
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	Connection** CheckConnection(int& ConC); // Function that makes list of Connections and their number.
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void RemoveComponent(Component* pComp);
	Component* GetComponent(int x, int y);
	bool selectcomponent(int x, int y);
	//To save in a text file
	void Save(ofstream& Output);
	Component* FindComponent(int ID);
	//destructor
	~ApplicationManager();
};

#endif
