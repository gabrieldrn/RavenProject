#pragma once
#include <vector>
#include <iosfwd>
#include <map>

#include "misc/utils.h"
#include "Raven_Bot.h"


class Raven_team
{

private:
	std::vector<Raven_Bot*> team;
	Vector2D spwanPoint;
	Raven_Bot* leader;
	Raven_Bot* target;


public:
	Raven_team();
	~Raven_team();

	Vector2D						 getSpawnPoint() { return spwanPoint;}
	std::vector<Raven_Bot*>          getTeamMate() { return team; }
	void							 addTeamMate(Raven_Bot* new_mate);

	Raven_Bot*				         getLeader() { return leader; }
	void							 setLeader(Raven_Bot* new_leader) { leader = new_leader;}

	Raven_Bot*				         getTarget() { return target; }
	void							 setTarget(Raven_Bot* new_target) {target = new_target;}



};

