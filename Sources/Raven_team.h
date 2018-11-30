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
	Vector2D spawnPoint;
	Raven_Bot* leader;
	Raven_Bot* target;
	bool	   isBlue;


public:
	Raven_team(Vector2D vec, bool couleur);
	~Raven_team();

	Vector2D						 getSpawnPoint() { return spawnPoint;}
	std::vector<Raven_Bot*>          getTeamMate() { return team; }
	void							 addTeamMate(Raven_Bot* new_mate);

	void							 sendMessageToTeam(int idMessage, Raven_Bot* id_bot);

	Raven_Bot*				         getLeader() { return leader; }
	void							 setLeader(Raven_Bot* new_leader) { leader = new_leader;}

	Raven_Bot*				         getTarget() { return target; }
	void							 setTarget(Raven_Bot* new_target) {target = new_target;}

	bool							 getBlue() { return isBlue; }
	void							 setBlue(bool new_bool) { isBlue = new_bool; }





};

