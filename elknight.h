#ifndef ELKNIGHT_H
#define ELKNIGHT_H
#include "creature.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

class elknight:public Creature
{
public:
    elknight();
    ~elknight();

    void skill1(vector<Creature*>, vector<Creature*> monsters);
    void skill2(vector<Creature*>, vector<Creature*> monsters);
};

#endif // ELKNIGHT_H
