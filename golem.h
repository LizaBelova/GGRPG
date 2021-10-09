#ifndef GOLEM_H
#define GOLEM_H
#include "creature.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class golem:public Creature
{
public:
    golem();
    ~golem();

    void skill1(vector<Creature*> heroes,vector<Creature*>);
    void skill2(vector<Creature*> heroes,vector<Creature*>);
};

#endif // GOLEM_H
