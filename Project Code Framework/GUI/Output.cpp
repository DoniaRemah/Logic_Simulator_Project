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
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
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
	pWind->SetPen(WHITE, 1);
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
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight2 + 12);
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT]; // Array of Strings (Adress of images)
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\BUFFER.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\NOT.jpg";
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
	for (int i = 0; i < 14; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, UI.ToolBarHeight2 + 2, UI.ToolItemWidth, UI.ToolItemHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
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
				pWind->DrawImage(MenuItemImages[i], (i - 14) * UI.ToolItemWidth, 0, UI.ToolItemWidth3, UI.ToolItemHeight2);
			else if (MenuItemImages[i] == "images\\Menu\\SWITCH_TO_SIM.jpg")
			{
				pWind->DrawImage(MenuItemImages[i], (i - 14) * UI.ToolItemWidth + UI.ToolItemWidth3, 0, UI.ToolItemWidth3, UI.ToolItemHeight2);
			}
		}
		else
		{
			if (MenuItemImages[i] == "images\\Menu\\EXIT.jpg")
				pWind->DrawImage(MenuItemImages[i], (i - 14) * UI.ToolItemWidth + (2 * UI.ToolItemWidth3), 0, UI.ToolItemWidth2, UI.ToolItemHeight2);
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
	// Deleting Design Menu Bar
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.StatusBarHeight);
	// Getting Adress of each icon.
	string SimItemImages[ITM_SIM_CNT];

	SimItemImages[ITM_SIM] = "images\\Menu\\Simulate_Circuit.jpg";
	SimItemImages[ITM_TRUTH] = "images\\Menu\\Truth_Table.jpg";
	SimItemImages[ITM_SWDSGN] = "images\\Menu\\Switch_To_Design.jpg";
	SimItemImages[ITM_PROB] = "images\\Menu\\Prob.jpg";
	SimItemImages[ITM_VALID] = "images\\Menu\\Valid_Circuit.jpg";
	// Drawing Icons of Sim Bar.
	for (int i = 0; i < ITM_SIM_CNT; i++)
	{
		pWind->DrawImage(SimItemImages[i], (i * UI.ToolItemWidth3), 0, UI.ToolItemWidth3, UI.ToolBarHeight2 + 10);

	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight2 + 12, UI.width, UI.ToolBarHeight2 + 12);
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//
//2AND
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_2AND.jpg";
	else
		GateImage = "Images\\Menu\\2AND.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components

//2NAND
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_2NAND.jpg";
	else
		GateImage = "Images\\Menu\\2NAND.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);

}

//2OR
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_2OR.jpg";
	else
		GateImage = "Images\\Menu\\2OR.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);

}

//2NOR
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_2NOR.jpg";
	else
		GateImage = "Images\\Menu\\2NOR.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);

}

//2XOR
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_2XOR.jpg";
	else
		GateImage = "Images\\Menu\\2XOR.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);

}
//2XNOR
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_2XNOR.jpg";
	else
		GateImage = "Images\\Menu\\2XNOR.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);

}
//BUFFER
void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_BUFFER.jpg";
	else
		GateImage = "Images\\Menu\\BUFFER.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFFER_Width, UI.BUFFER_Height);

}
//NOT
void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_NOT.jpg";
	else
		GateImage = "Images\\Menu\\NOT.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);

}
//3AND
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_3AND.jpg";
	else
		GateImage = "Images\\Menu\\3AND.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);

}
//3NOR
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_3NOR.jpg";
	else
		GateImage = "Images\\Menu\\3NOR.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);

}
//3XOR
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_3XOR.jpg";
	else
		GateImage = "Images\\Menu\\3XOR.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);

}
//SWITCH
void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_SWITCH_OFF.jpg";
	else
		GateImage = "Images\\Menu\\SWITCH_OFF.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);

}
//BULB
void Output::DrawBULB(GraphicsInfo r_GfxInfo, bool selected)const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\H_BULB_OFF.jpg";
	else
		GateImage = "Images\\Menu\\BULB_OFF.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BULB_Width, UI.BULB_Height);

}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
}


Output::~Output()
{
	delete pWind;
}
