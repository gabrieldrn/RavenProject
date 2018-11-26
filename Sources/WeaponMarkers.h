#ifndef WEAPON_MARKERS_H
#define WEAPON_MARKERS_H
#pragma warning (disable : 4786)
//-----------------------------------------------------------------------------
//
//  Name:   GraveMarkers.h
//
//  Author: Mat Buckland (ai-junkie.com)
//
//  Desc:   Class to record and render graves at the site of a bot's death
//
//-----------------------------------------------------------------------------
#include <list>
#include <vector>
#include "2d/vector2d.h"
#include "time/crudetimer.h"
#include "Raven_Bot.h"
#include "Raven_team.h"

class WeaponMarkers
{
private:

	//vrtex buffers for rocket shape
	std::vector<Vector2D>	m_vecRLVB;
	std::vector<Vector2D>	m_vecRLVBTrans;


	struct WeaponRecord
	{
		Vector2D Position;
		int	weaponType;

		WeaponRecord(Vector2D pos, int newWeaponType) :
			Position(pos),
			weaponType(newWeaponType){}
	};

private:

	typedef std::list<WeaponRecord> WeaponList;

private:
	WeaponList              m_WeaponList;

public:

	WeaponMarkers();

	void Update();
	void Render();
	void AddWeapon(Vector2D pos, int weaponType);
};

#endif