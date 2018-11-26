#include "TriggerWeapon.h"
#include "misc/Cgdi.h"
#include "misc/Stream_Utility_Functions.h"
#include <fstream>
#include "./lua/Raven_Scriptor.h"
#include "./constants.h"
#include "./Raven_ObjectEnumerations.h"
#include "./Raven_WeaponSystem.h"
#include "Debug/DebugConsole.h"
#include "../Common/Game/BaseGameEntity.h"


TriggerWeapon::TriggerWeapon(Vector2D pos, double range, int wepon_type): 
	Trigger_Respawning<Raven_Bot>(GetNextValidID()),
	t_position(pos), 
	t_range(range),
	t_type(wepon_type),
	t_active(true)
{
	SetPos(pos);
	AddCircularTriggerRegion(pos, 7.0);


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

void TriggerWeapon::Try(Raven_Bot * pBot)
{
	if (this->isTouchingTrigger(pBot->Pos(), pBot->BRadius()))
	{
		pBot->GetWeaponSys()->AddWeapon(t_type);
		t_active = false;
	}

}

void TriggerWeapon::Read()
{
	SetPos(Pos());
	SetBRadius(t_range);
	//create this trigger's region of fluence
	AddCircularTriggerRegion(Pos(), script->GetDouble("DefaultGiverTriggerRange"));

}


void TriggerWeapon::Render()
{
	if (t_active)
	{
		switch (t_type)
		{
		case type_rail_gun:
		{
			gdi->BluePen();
			gdi->BlueBrush();
			gdi->Circle(Pos(), 3);
			gdi->ThickBluePen();
			gdi->Line(Pos(), Vector2D(Pos().x, Pos().y - 9));
		}

		break;

		case type_shotgun:
		{
			gdi->BlackBrush();
			gdi->BrownPen();
			const double sz = 3.0;
			gdi->Circle(Pos().x - sz, Pos().y, sz);
			gdi->Circle(Pos().x + sz, Pos().y, sz);
		}

		break;

		case type_rocket_launcher:
		{
			Vector2D facing(-1, 0);

			m_vecRLVBTrans = WorldTransform(m_vecRLVB,
				Pos(),
				facing,
				facing.Perp(),
				Vector2D(2.5, 2.5));

			gdi->RedPen();
			gdi->ClosedShape(m_vecRLVBTrans);
		}

		break;
		}//end switch
	}
}