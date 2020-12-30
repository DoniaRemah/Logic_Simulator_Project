#include "DrawConnection.h"
#include "ApplicationManager.h"
DrawConnection :: DrawConnection(ApplicationManager* pApp) :Action(pApp)
{

}

DrawConnection :: ~DrawConnection(void)
{

}

void DrawConnection::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("DRAWING CONNECTION. Choose input and output pin.");
	// Setting Potential Parameters.
	int x1;
	int y1;
	int x2;
	int y2;
	int valid = 0;
	while (valid == 0)
	{
		pIn->GetPointClicked(x1, y1);
		pIn->GetPointClicked(x2, y2);
		if (x1)
		{
			
		}
	}

	pOut->ClearStatusBar();
}