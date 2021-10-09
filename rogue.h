#ifndef ROGUE_H
#define ROGUE_H
#include "creature.h"
#include <iostream>

using namespace std;

class rogue: public Creature
{
public:
    rogue();
    ~rogue();

    void skill1(vector<Creature*>, vector<Creature*> monsters);
    void skill2(vector<Creature*>,vector<Creature*> monsters);
};

#endif // ROGUE_H
