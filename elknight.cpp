#include "elknight.h"

elknight::elknight()
{
    set_name("Cursed Knight");
    set_hp(400);
    set_max_hp(400);
    set_def(210);
    set_atk(100);
    set_max_atk(100);
    set_mana(0);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}

elknight::~elknight()
{

}

void elknight::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    int i=rand()%monsters.size();
    cout<<"Cursed Knight gives +30 DEF to "<<monsters[i]->get_name()<<endl;
    monsters[i]->set_def(50);
}

void elknight::skill2(vector<Creature *>, vector<Creature *> monsters)
{
    int i=rand()%monsters.size();
    if(monsters[i]->get_status(4)){
        cout<<"Cursed Knight removed debuf from "<<monsters[i]->get_name()<<endl;
        monsters[i]->set_atk(-monsters[i]->get_atk()+monsters[i]->get_max_atk());
        monsters[i]->set_status(4,false);
        monsters[i]->set_status_cont(4,-1);
        return;
    }
    cout<<"Cursed Knight gives buf +30 ATK to "<<monsters[i]->get_name()<<endl;
    monsters[i]->set_atk(30);
    monsters[i]->set_status(3,true);
    monsters[i]->set_status_cont(3,1-monsters[i]->get_status_cont(3));
}

