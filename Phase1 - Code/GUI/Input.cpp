//#include "Input.h"
#include "Output.h"
#include <iostream>
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut)
{
	//backspace=8,enter=13,escape=27
	string message;
	char key;
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();
	while (true)
	{
		pOut->PrintMsg("Set Commponent label: " + message);
		pWind->WaitKeyPress(key);
		//check the type of key  
		if (key == 8)//if the key is backspace
		{
			if (!message.empty())//check if the string is empty or not 
				message.pop_back();//if the string is not empty ,delete the element in string
			else
				break;
		}
		else if (key == 27)//if the key is escape
		{
			message.clear();//delete all the element of string
			break;
		}
		else if (key == 13)//if the key is enter
			break;
		else
			message.push_back(key);
	}
	pOut->ClearStatusBar();
	return message;
}
//This function reads the position where the user clicks to determine the desired action.
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar1(GATES)
		
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			if (y < UI.ToolBarHeight && y > UI.ToolBarHeight2)
			{
				int ClickedItemOrder = (x / UI.ToolItemWidth);
				switch (ClickedItemOrder)
				{
				case ITM_BUFFER: return ADD_Buff;
				case ITM_NOT: return ADD_INV;
				case ITM_AND2: return ADD_AND_GATE_2;
				case ITM_AND3: return ADD_AND_GATE_3;
				case ITM_OR2: return ADD_OR_GATE_2;
				case ITM_NAND2: return ADD_NAND_GATE_2;
				case ITM_NOR2: return ADD_NOR_GATE_2;
				case ITM_XOR2: return ADD_XOR_GATE_2;
				case ITM_XNOR2: return ADD_XNOR_GATE_2;
				case ITM_NOR3: return ADD_NOR_GATE_3;
				case ITM_XOR3: return ADD_XOR_GATE_3;
				case ITM_SWITCH: return ADD_Switch;
				case ITM_BULB: return ADD_LED;
				case ITM_WIRE: return ADD_CONNECTION;
				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				}
			}
			
			// IF THE USER CLICKS ON TOOLBAR2
			
			if (y >= 0 && y < UI.ToolBarHeight2)
				{
						if (0 <= x && x < 465)

						{
							if (x > 420 && x < 460)
							{
								return SAVE;
							}
							else if (x > 350 && x < 390)
							{
								return LOAD;
							}
							else if (x > 280 && x < 320)
							{
								return PASTE;
							}
							else if (x > 210 && x < 250)
							{
								return COPY;
							}
							else if (x > 140 && x < 180)
							{
								return CUT;
							}
							else if (x > 70 && x < 110)
							{
								return EDIT_Label;
							}
							else if (x > 0 && x < 40 )
							{
								return ADD_Label;
							}
							else
							{
								cout << x << endl;
								return DSN_TOOL;
							}
						}
						else if (x > 490 && x < 590  )
						{
							return MULTI_SELECT;

						}
						else if (x > 660 && x < 760)
						{
							return SIM_MODE;
						}
						
						else if (x > 830 && x <870)
						{
							return	EXIT;
						}
						else
						{
							return DSN_TOOL;
						}
					}
			
		

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		if (y <= UI.height && y > (UI.height - UI.StatusBarHeight)) 
		{
			return STATUS_BAR;
		}
		//[3] User clicks on the status bar
		
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
