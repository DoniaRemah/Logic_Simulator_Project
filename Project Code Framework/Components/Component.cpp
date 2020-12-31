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

Component::~Component()
{}

GraphicsInfo Component::GetGfxInfo()
{
	return m_GfxInfo;
}