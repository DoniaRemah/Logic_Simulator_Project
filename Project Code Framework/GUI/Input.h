#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window

public:
	Input(window*);
	void GetPointClicked(int&, int&);	//Get coordinate where user clicks
	string GetSrting(Output*, string msg,string message2);		//Returns a string entered by the user

	ActionType GetUserAction(int* r_x = 0, int* r_y = 0) const; //Reads the user click and maps it to an action

	~Input();
};
