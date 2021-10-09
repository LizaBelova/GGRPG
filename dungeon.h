#ifndef DUNGEON_H
#define DUNGEON_H
#include "creature.h"
#include "knight.h"
#include "priest.h"
#include "goblin.h"
#include <vector>

class dungeon
{
public:
    dungeon();
    vector<Creature> heroes;
    void hero_squad(Creature &hero);
    //void the_game();



};

#endif // DUNGEON_H
