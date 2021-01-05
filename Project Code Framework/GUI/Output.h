#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;   //Pointer to the Graphics Window
	Input* pIn; 	
public:
	Output(); // Performs the Window Initialization (Creates Window)
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void CreateDesignToolBar() const;	//Tool bar 1 of the design mode
	void CreateDesignToolBar2() const; // Tool Bar 2 of design mode.
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void Cleartextindrawingarea(int x, int y) const;
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window


	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawNOT(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected = false)const;
	void DrawBULB(GraphicsInfo r_GfxInfo, bool selected = false)const;

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	bool IsDrawingArea(int x, int y);
	

	void PrintMsg(string msg) const;	//Print a message on Status bar
	void Output::DrawString(const int iX, const int iY, const string strText)const;

	~Output();
};
