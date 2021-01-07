#include "InputPin.h"

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
