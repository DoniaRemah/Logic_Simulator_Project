#include "InputPin.h"
#include"Connection.h"

InputPin::InputPin():connected(false)
{

}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

bool InputPin::IsConnected()
{
	return connected;
}

void InputPin::connect()
{
	connected = true;
}

void InputPin::unConnect()
{
	connected = false;
	pComp = NULL;
}
int InputPin::GetCompID() {
	return pComp->GetID();
}
void InputPin::SetConnectionStat(bool x)
{
	connected = x;
}
bool InputPin::GetConnectionStat()
{
	return connected;
}
void InputPin::SetConnection(Connection* ptrIn)
{
	pIn = ptrIn;
}