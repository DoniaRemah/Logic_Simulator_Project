#include "Component.h"
Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
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

void Component::DeleteComp(Output* pOut,GraphicsInfo delgfx)
{
	pOut->ClearPartArea(delgfx.x1, delgfx.y1, delgfx.x2, delgfx.y2);
}

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
