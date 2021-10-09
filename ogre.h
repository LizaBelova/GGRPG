#ifndef OGRE_H
#define OGRE_H
#include "creature.h"
#include <iostream>

using namespace std;

class ogre:public Creature
{
public:
    ogre();
    ~ogre();

    void skill1(vector<Creature*>, vector<Creature*> monsters);
    void skill2(vector<Creature*>,vector<Creature*>);
};

#endif // OGRE_H
