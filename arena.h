#ifndef ARENA_H
#define ARENA_H
#include "creature.h"

#include "knight.h"
#include "priest.h"
#include "mage.h"
#include "rogue.h"
#include "archer.h"
#include "beast.h"

#include "spider.h"
#include "goblin.h"
#include "ogre.h"
#include "shaman.h"
#include "elemental.h"
#include "golem.h"
#include "elarcher.h"
#include "elknight.h"
#include "elmage.h"
#include "dragon.h"

#include <cstdlib>
#include <ctime>
#include <vector>

class arena
{

public:
    arena();
    vector<Creature*> heroes;
    vector<Creature*> monsters;

    void death_monster(int num);
    void death_hero(int num);
    void wave(unsigned int dif);
    void hero_squad();
    void auto_hero_squad();
    void arena_wave(int dif);

    void the_game();
    void arena_fight();

    void check_hbuf(int turn);
    void check_mbuf(int turn);
    void check_hstatus(int num);
    void check_mstatus(int num);
    void mana_up();
    void restore();
    void use_hp_potion(int turn);
    void use_mp_potion(int turn);

    bool m_can_cast1(int num);
    bool m_can_cast2(int num);
};

#endif // ARENA_H
