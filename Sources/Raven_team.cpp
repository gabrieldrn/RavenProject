#include "Raven_team.h"
#include <vector>
#include <iosfwd>
#include <map>

#include "misc/utils.h"
#include "Raven_Bot.h"



Raven_team::Raven_team()
{
	std::vector<Raven_Bot *> team =  std::vector<Raven_Bot *>();
	leader = NULL;
}


Raven_team::~Raven_team()
{
}

void Raven_team::addTeamMate(Raven_Bot * new_mate)
{
	team.push_back(new_mate);
	new_mate->SetTeam(this);

	if (leader == NULL) {
		leader = new_mate;
	}
}
