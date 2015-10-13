#include "healer.h"

using namespace std;

Healer::Healer(string name) : Player(name) {
	// nothing to do here
}

void Healer::doAction(Player *target) {
	if (!target) return;
	// healer restores 75 hp to the target up to the maxHP limit
	if (target->getHP()+75<target->getMaxHP()) {
		// set
		target->setHP(target->getHP()+75);
	} else {
		// set to max
		target->setHP(target->getMaxHP());
	}
}