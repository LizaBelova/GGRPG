#ifndef DRAGON_H
#define DRAGON_H
#include "creature.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class dragon:public Creature
{
public:
    dragon();
    ~dragon();

    void skill1(vector<Creature*> heroes, vector<Creature*>);
    void skill2(vector<Creature*> heroes,vector<Creature*>);
};

#endif // DRAGON_H
