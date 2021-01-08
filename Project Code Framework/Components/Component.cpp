#include "Component.h"
#include<fstream>
Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	countNextComp = 0;
}

bool Component :: InsideArea(int x, int y)
{

	if ((x >= m_GfxInfo.x1) && (x <= m_GfxInfo.x2) && (y >= m_GfxInfo.y1) && (y <= m_GfxInfo.y2))
	{
		return true;
	}
	else
	{
		return false;
	}
}


Component::Component()
{}


Component::~Component()
{}

GraphicsInfo Component::GetGfxInfo()
{
	return m_GfxInfo;
}

string Component::GetLabel()
{
	return m_Label;
}

void Component::SetLabel(string NewLabel)
{
	m_Label = NewLabel;
}
void Component::SetNextComp(Component* ptrComp) 
{
	nextComp.push_back(ptrComp); //Vector function that adds a component from the back
	countNextComp++;
}
Component* Component::GetNextComp(int count)
{
	if (count + 1 > countNextComp) return NULL;
	return nextComp.at(count);
}