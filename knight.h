#ifndef KNIGHT_H
#define KNIGHT_H
#include "creature.h"
#include <iostream>

using namespace std;

class knight:public Creature
{
public:
    knight();
    ~knight();

    void skill1(vector<Creature*>,vector<Creature*>);
    void skill2(vector<Creature*>,vector<Creature*>);
};

#endif // KNIGHT_H
