#ifndef ARCHER_H
#define ARCHER_H
#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class archer:public Creature
{
public:
    archer();
    ~archer();

    void skill1(vector<Creature*>, vector<Creature*> monsters);
    void skill2(vector<Creature*>,vector<Creature*> monsters);
};

#endif // ARCHER_H
