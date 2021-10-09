#ifndef MAGE_H
#define MAGE_H
#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class mage:public Creature
{
public:
    mage();
    ~mage();

    void skill1(vector<Creature*>,vector<Creature*> monsters);
    void skill2(vector<Creature*>,vector<Creature*> monsters);
};

#endif // MAGE_H
