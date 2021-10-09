#ifndef ELARCHER_H
#define ELARCHER_H
#include "creature.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

class elarcher:public Creature
{
public:
    elarcher();
    ~elarcher();

    void skill1(vector<Creature*> heroes, vector<Creature*>);
    void skill2(vector<Creature*>,vector<Creature*>);
};

#endif // ELARCHER_H
