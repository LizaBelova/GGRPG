#ifndef SHAMAN_H
#define SHAMAN_H
#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class shaman:public Creature
{
public:
    shaman();
    ~shaman();

    void skill1(vector<Creature*>, vector<Creature*> monsters);
    void skill2(vector<Creature*>,vector<Creature*>);
};

#endif // SHAMAN_H
