#ifndef GOBLIN_H
#define GOBLIN_H
#include "creature.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class goblin:public Creature
{
public:
    goblin();
    ~goblin();

    void skill1(vector<Creature*> heroes, vector<Creature*> monsters);
    void skill2(vector<Creature*> heroes, vector<Creature*>);
};

#endif // GOBLIN_H
