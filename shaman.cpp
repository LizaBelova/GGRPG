#include "shaman.h"

shaman::shaman()
{
    set_name("Shaman");
    set_hp(100);
    set_max_hp(100);
    set_def(150);
    set_atk(50);
    set_max_atk(50);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}

void shaman::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    cout<<endl<<"Shaman restore allies"<<endl;
    for(int unsigned i=0;i<monsters.size();i++){
        if(monsters[i]->get_max_hp()-monsters[i]->get_hp()<50) {
            cout<<monsters[i]->get_name()<<" restore "<<monsters[i]->get_max_hp()-monsters[i]->get_hp()<<" HP and 10 DEF"<<endl;
            monsters[i]->set_hp(monsters[i]->get_max_hp()-monsters[i]->get_hp());
            monsters[i]->set_def(10);
        }
        else {
            cout<<monsters[i]->get_name()<<" restore 50 HP and 10 DEF"<<endl;
            monsters[i]->set_hp(50);
            monsters[i]->set_def(10);
        }
    }
}

void shaman::skill2(vector<Creature *>, vector<Creature *>)
{

}


shaman::~shaman()
{

}
