#ifndef ELMAGE_H
#define ELMAGE_H
#include "creature.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

class elmage:public Creature
{
public:
    elmage();
    ~elmage();

    void skill1(vector<Creature*>, vector<Creature*> monsters);
    void skill2(vector<Creature*> heroes, vector<Creature*>);
};

#endif // ELMAGE_H
