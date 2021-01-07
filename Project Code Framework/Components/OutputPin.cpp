#include "OutputPin.h"
#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections.
		return true;
	}
	
	return false;	//can't connect to any more connections
}

void OutputPin::setComponent(Component* pCmp)
{
	this->pComp = pCmp;
}

Component* OutputPin::getComponent()
{
	return pComp;
}

void OutputPin::unConnect(Connection * d_Conn)
{
	// Shifts the connections in the list.
	for (int i=0;i< m_Conn;i++)
	{
		if (m_Connections[i] == d_Conn)
		{
			if (i == m_FanOut-1)
			{
				m_Connections[i] = NULL;
				m_Conn--;
			}
			else
			{
				m_Connections[i] = m_Connections[m_FanOut - 1];
				m_Connections[m_FanOut - 1] = NULL;
				m_Conn--;
			}
			
		}
	}
}

bool OutputPin::CanConnect()
{
	if (m_Conn < m_FanOut)
	{
		return true; // can add connection
	}
	else
	{
		return false;	//can't connect to any more connections
	}
	
}

bool OutputPin::IsConnected()
{
	if (m_Conn!=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int OutputPin::GetCompID() 
{
	return pComp->GetID();
}