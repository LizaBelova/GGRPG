#ifndef PRIEST_H
#define PRIEST_H
#include "creature.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class priest:public Creature
{
public:
    priest();
    ~priest();

    void skill1(vector<Creature*> heroes, vector<Creature*>);
    void skill2(vector<Creature*> heroes,vector<Creature*> monsters);
};

#endif // PRIEST_H
