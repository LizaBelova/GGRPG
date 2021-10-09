#include "spider.h"

spider::spider()
{
    set_name("Spider");
    set_hp(90);
    set_max_hp(90);
    set_def(70);
    set_atk(70);
    set_max_atk(70);
    set_mana(0);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}


void spider::skill1(vector<Creature *> heroes, vector<Creature *>)
{
    int tar=rand()%heroes.size();
    for(int i=0;i<heroes.size();i++){
        if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {tar=i; break;}
    }
    if(heroes[tar]->get_name()=="Knight" && heroes[tar]->get_status(0)){
        cout<<"Spider bites Knight, but Knight raised shield"<<endl;
        return;
    }
    cout<<"Spider bites "<<heroes[tar]->get_name()<<" and imposes poisoning"<<endl;
    heroes[tar]->set_status(6,true);
    heroes[tar]->set_status_cont(6,3-heroes[tar]->get_status_cont(6));
}

void spider::skill2(vector<Creature *> heroes, vector<Creature *>)
{
    int tar=rand()%heroes.size();
    for(int i=0;i<heroes.size();i++){
        if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {tar=i; break;}
    }
    if(heroes[tar]->get_name()=="Knight" && heroes[tar]->get_status(0)){
        cout<<"Spider used Web on Knight, but Knight raised shield"<<endl;
        return;
    }
    cout<<"Spider used Web on "<<heroes[tar]->get_name()<<" and imposes Stan"<<endl;
    heroes[tar]->set_status(7,true);
    heroes[tar]->set_status_cont(7,1-heroes[tar]->get_status_cont(7));
}

spider::~spider()
{

}
