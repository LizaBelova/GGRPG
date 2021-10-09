#ifndef SPIDER_H
#define SPIDER_H
#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class spider:public Creature
{
public:
    spider();
    ~spider();

    void skill1(vector<Creature*> heroes, vector<Creature*>);
    void skill2(vector<Creature*> heroes, vector<Creature*>);
};

#endif // SPIDER_H
