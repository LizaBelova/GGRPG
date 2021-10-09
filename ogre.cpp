#include "ogre.h"

ogre::ogre()
{
    set_name("Ogre");
    set_hp(170);
    set_max_hp(170);
    set_def(75);
    set_atk(75);
    set_max_atk(75);
    set_mana(0);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}


void ogre::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    int target;
    for(int unsigned i=0;i<monsters.size();i++){
        if(monsters[i]->get_name()=="Goblin") {
            target=i;
            break;
        }
    }
    cout<<endl<<"Ogre ate goblin"<<endl;
    set_hp(monsters[target]->get_hp()/2);
    set_max_hp(monsters[target]->get_max_hp()/2);
    set_atk(monsters[target]->get_max_atk()/2);
    set_max_atk(monsters[target]->get_max_atk()/2);
    set_def(monsters[target]->get_def()/2);

    cout<<"+"<<monsters[target]->get_hp()/2<<" HP ";
    cout<<"+"<<monsters[target]->get_max_atk()/2<<" ATK ";
    cout<<"+"<<monsters[target]->get_def()/2<<" DEF ";
    monsters[target]->set_status(2,true);
}

void ogre::skill2(vector<Creature *>, vector<Creature *>)
{

}


ogre::~ogre()
{

}
