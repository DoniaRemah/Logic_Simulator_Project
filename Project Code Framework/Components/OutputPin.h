#ifndef _OUTPUTPIN_H
#define _OUTPUTPIN_H

/*class OutputPin 
  ---------------
 An output pin obtains its value as a result of calculating the outputs of
 a component. The output pin propagates its value immediately to the associated connections
*/

#include "Pin.h"
class Connection;	//Forward class declartion
class Component; //Forward class declaration

class OutputPin: public Pin	//inherited from class Pin
{
private:
	//Array of connections (poniters) to be connected to that OutputPin
	//For simplicity, we consider it a constant length
	Connection* m_Connections[MAX_CONNS];	
	int m_FanOut;	//Maximum No. of connections connected to that output pin (depends on the component)
	int m_Conn;		//Actual No. of connections connected to that output pin
	Component* pComp; //Component at which this pin is associated

	int CompID; //ID for saving to files
public:
	OutputPin(int r_FanOut);	
	bool ConnectTo(Connection *r_Conn);	//connect to a new connection
	void setComponent(Component* pCmp);	//sets the component of this Output Pin
	Component* getComponent();	//returns the component of this Output pin
	void unConnect(Connection * d_Conn);
	bool CanConnect();
	bool IsConnected();
	int GetCompID();
};

#endif