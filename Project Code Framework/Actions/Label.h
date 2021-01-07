#ifndef _Label_H
#define _Label_H

#include "action.h"
#include "..\Components\component.h"

class Label : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;   //Two corners of the rectangluar area
	Component* mComp;
	string newlabel;
public:
	Label(ApplicationManager* pApp);
	virtual ~Label(void);

	//Reads parameters required for action to execute
	virtual bool ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif

