#ifndef BEAST_H
#define BEAST_H
#include "creature.h"
#include "iostream"

using namespace std;

class beast:public Creature
{
public:
    beast();
    ~beast();

    void skill1(vector<Creature*>, vector<Creature*> monsters);
    void skill2(vector<Creature*>,vector<Creature*> monsters);
};

#endif // BEAST_H
