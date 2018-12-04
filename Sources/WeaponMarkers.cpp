#include "WeaponMarkers.h"
#include "misc/cgdi.h"
#include "2D/Transformations.h"
#include "Raven_Bot.h"
#include "Raven_team.h"
#include "Raven_ObjectEnumerations.h"
#include "Debug/DebugConsole.h"
//------------------------------- ctor ----------------------------------------
//-----------------------------------------------------------------------------
WeaponMarkers::WeaponMarkers()
{
	//create the vertex buffer for the rocket shape
	const int NumRocketVerts = 8;
	const Vector2D rip[NumRocketVerts] = { Vector2D(0, 3),
										 Vector2D(1, 2),
										 Vector2D(1, 0),
										 Vector2D(2, -2),
										 Vector2D(-2, -2),
										 Vector2D(-1, 0),
										 Vector2D(-1, 2),
										 Vector2D(0, 3) };

	for (int i = 0; i < NumRocketVerts; ++i)
	{
		m_vecRLVB.push_back(rip[i]);
	}
}

void WeaponMarkers::Update()
{
	WeaponList::iterator it = m_WeaponList.begin();
	while (it != m_WeaponList.end())
	{

	}
}

void WeaponMarkers::Render()
{
	WeaponList::iterator it = m_WeaponList.begin();
	Vector2D pos;
	
	for (it; it != m_WeaponList.end(); ++it)
	{
		pos = it->Position;

		switch (it->weaponType)
		{
		case type_rocket_launcher: 
		{
			Vector2D facing(-1, 0);

			m_vecRLVBTrans = WorldTransform(m_vecRLVB,
				Vector2D (pos.x -15, pos.y),
				facing,
				facing.Perp(),
				Vector2D(2.5, 2.5));

			gdi->RedPen();
			gdi->ClosedShape(m_vecRLVBTrans);
		}

			break;

		case type_shotgun:
		{
			gdi->BlackBrush();
			gdi->BrownPen();
			const double sz = 3.0;
			gdi->Circle(pos.x - sz + 15, pos.y, sz);
			gdi->Circle(pos.x + sz + 15, pos.y, sz);

		}
		break;

		case type_rail_gun:
		{
			gdi->BluePen();
			gdi->BlueBrush();
			gdi->Circle(pos, 3);
			gdi->ThickBluePen();
			gdi->Line(pos, Vector2D(pos.x, pos.y - 9));
		}
			break;
		}
	}
}

void WeaponMarkers::AddWeapon(Vector2D pos, int weaponType)
{
	m_WeaponList.push_back(WeaponRecord(pos, weaponType));
}