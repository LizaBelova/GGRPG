#ifndef ELEMENTAL_H
#define ELEMENTAL_H
#include "creature.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class elemental:public Creature
{
public:
    elemental();
    ~elemental();

    void skill1(vector<Creature*> heroes, vector<Creature*>);
    void skill2(vector<Creature*> heroes, vector<Creature*>);
};

#endif // ELEMENTAL_H
