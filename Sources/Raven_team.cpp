#include "Raven_team.h"
#include <vector>
#include <iosfwd>
#include <map>

#include "Messaging/Telegram.h"
#include "Raven_Messages.h"
#include "Messaging/MessageDispatcher.h"

#include "misc/utils.h"
#include "Raven_Bot.h"

#include "Debug/DebugConsole.h"


Raven_team::Raven_team(Vector2D vec, bool couleur) : spawnPoint(vec), isBlue(couleur)
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

void Raven_team::sendMessageToTeam(int idMessage, Raven_Bot* bot_injured)
{
	Vector2D position = bot_injured->Pos();

	for (std::vector<Raven_Bot*>::iterator it = team.begin(); it != team.end(); ++it) {
		

		if (bot_injured->ID() != (*it)->ID()) {
			Dispatcher->DispatchMsg(
				SEND_MSG_IMMEDIATELY,
				bot_injured->ID(),
				(*it)->ID(),
				idMessage,
				&position);
			
		}


	}
		


}
