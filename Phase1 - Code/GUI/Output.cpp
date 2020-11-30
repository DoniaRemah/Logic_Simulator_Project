#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();
	CreateDesignToolBar2();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
void Output::DrawString(const int iX, const int iY, const string strText)const {
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawString(iX, iY, (char*)strText.c_str());

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar1) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT]; // Array of Strings (Adress of images)
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\BUFFER.jpg";
	MenuItemImages[ITM_NOT]  = "images\\Menu\\NOT.jpg";
	MenuItemImages[ITM_AND2] = "images\\Menu\\2AND.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\3AND.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\2OR.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\2NAND.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\2NOR.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\3NOR.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\2XOR.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\3XOR.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\2XNOR.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\SWITCH_OFF.jpg";
	MenuItemImages[ITM_BULB] = "images\\Menu\\BULB_OFF.jpg";
	MenuItemImages[ITM_WIRE] = "images\\Menu\\WIRE.jpg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i< 14; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth, UI.ToolBarHeight2+2,UI.ToolItemWidth, UI.ToolItemHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
// Draws the menu (Toolbar2) in the design Mode.
void Output::CreateDesignToolBar2() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT]; // Array of Strings (Adress of images)
	MenuItemImages[ITM_LABEL] = "images\\Menu\\LABEL.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\EDIT.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\CUT.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\COPY.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\PASTE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\LOAD.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\SAVE.jpg";
	MenuItemImages[ITM_MULTI_SELECT] = "images\\Menu\\MULTI_SELECT.jpg";
	MenuItemImages[ITM_SWITCH_TO_SIM] = "images\\Menu\\SWITCH_TO_SIM.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\EXIT.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 14; i < ITM_DSN_CNT; i++)
	{
		if (MenuItemImages[i] == "images\\Menu\\SWITCH_TO_SIM.jpg" || MenuItemImages[i] == "images\\Menu\\MULTI_SELECT.jpg")
		{
			if (MenuItemImages[i] == "images\\Menu\\MULTI_SELECT.jpg")
				pWind->DrawImage(MenuItemImages[i], (i-14) * UI.ToolItemWidth, 0, UI.ToolItemWidth3, UI.ToolItemHeight2);
			else if (MenuItemImages[i] == "images\\Menu\\SWITCH_TO_SIM.jpg")
			{
				pWind->DrawImage(MenuItemImages[i], (i - 14) * UI.ToolItemWidth + UI.ToolItemWidth3, 0, UI.ToolItemWidth3, UI.ToolItemHeight2);
			}
		}
		else
		{
				if (MenuItemImages[i] == "images\\Menu\\EXIT.jpg")
					pWind->DrawImage(MenuItemImages[i], (i - 14) * UI.ToolItemWidth + (2*UI.ToolItemWidth3), 0, UI.ToolItemWidth2, UI.ToolItemHeight2);
				else
				{
					pWind->DrawImage(MenuItemImages[i], (i - 14) * UI.ToolItemWidth, 0, UI.ToolItemWidth2, UI.ToolItemHeight2);
				}
		}
		
	}


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight2, UI.width, UI.ToolBarHeight2);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
}


Output::~Output()
{
	delete pWind;
}
