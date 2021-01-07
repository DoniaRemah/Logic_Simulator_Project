#pragma once

#include "Action.h"
#include"..\ApplicationManager.h"
#include"..\Components\Gate.h"
#include"..\Components\LED.h"
#include"..\Components\SWITCH.h"
#include"..\Components\Connection.h"

#include<fstream>
class Saving : public Action
{
private:
	ApplicationManager* pApp;
	int Cx, Cy;	
	int x1, y1, x2, y2;	
	ofstream Outputfile;
public:
	Saving(ApplicationManager* pApp);
	virtual ~Saving(void);

	
	virtual bool ReadActionParameters();
	
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

