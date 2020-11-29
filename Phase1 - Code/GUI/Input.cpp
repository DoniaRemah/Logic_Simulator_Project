//#include "Input.h"
#include "Output.h"

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
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	return NULL;
}

//This function reads the position where the user clicks to determine the desired action.
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar1(GATES)
		
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
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
			// IF THE USER CLICKS ON TOOLBAR2
				if (y >= 0 && y < UI.ToolBarHeight)
				{
					if (y >= UI.ToolBarHeight && y < UI.ToolBarHeight2)
					{

						int ClickedItemOrder = (x / UI.ToolItemWidth);
						if (0 <= ClickedItemOrder && ClickedItemOrder < (7 * UI.ToolItemWidth2))

						{
							switch (ClickedItemOrder)
							{
							case ITM_LABEL: return ADD_Label;
							case ITM_EDIT: return EDIT_Label;
							case ITM_CUT: return CUT;
							case ITM_COPY: return COPY;
							case ITM_PASTE: return PASTE;
							case ITM_LOAD: return LOAD;
							case ITM_SAVE: return SAVE;
							


							default: return DSN_TOOL;

							}
						}
						else if (ClickedItemOrder > (7 * UI.ToolItemWidth2) && ClickedItemOrder < (2 * UI.ToolItemWidth3))
						{
							switch (ClickedItemOrder)
							{
							case ITM_MULTI_SELECT: return MULTI_SELECT;
							case ITM_SWITCH_TO_SIM: return SIM_MODE;
							default: return DSN_TOOL;

							}
						}
						else if (ClickedItemOrder > (2 * UI.ToolItemWidth3) && ClickedItemOrder < UI.width)
						{
							EXIT;
						}
					}
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			
		}
	
	

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
