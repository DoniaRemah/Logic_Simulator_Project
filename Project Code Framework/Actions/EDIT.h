
ifndef _EDIT_H
#define _EDIT_H

#include "action.h"
#include "..\Components\component.h"

class EDIT : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;   //Two corners of the rectangluar area
	Component* mComp;
	string Editlabel;
	string privlabel;
public:
	EDIT(ApplicationManager* pApp);
	virtual ~EDIT(void);

	//Reads parameters required for action to execute
	virtual bool ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
