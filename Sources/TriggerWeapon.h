#ifndef TRIGGER_WEAPON_H
#define TRIGGER_WEAPON_H
#pragma warning (disable:4786)

#include "Triggers/Trigger.h"
#include "Triggers/Trigger_Respawning.h"
#include "Raven_Bot.h"
#include <iosfwd>

class TriggerWeapon : public Trigger_Respawning<Raven_Bot>
{
private:

	//vrtex buffers for rocket shape
	std::vector<Vector2D>         m_vecRLVB;
	std::vector<Vector2D>         m_vecRLVBTrans;

	Vector2D	t_position;
	double		t_range;
	int			t_type;

	bool		t_active;

public:

	//this type of trigger is created when reading a map file
	TriggerWeapon(Vector2D pos, double range, int wepon_type);

	//if triggered, this trigger will call the PickupWeapon method of the
	//bot. PickupWeapon will instantiate a weapon of the appropriate type.
	void Try(Raven_Bot* pBot);

	//draws a symbol representing the weapon type at the trigger's location
	void Render();

	void Read();
};

#endif