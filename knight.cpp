#include "knight.h"

knight::knight()
{
    set_name("Knight");
    set_hp(600);
    set_max_hp(600);
    set_def(600);
    set_atk(100);
    set_max_atk(100);
    set_mana(40);
    skill_name1="Rise the shield (5)";
    skill_name2="Agression (5)";
    skill1_mana=5;
    skill2_mana=5;
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }

}



void knight::skill1(vector<Creature*>,vector<Creature*>)
{
    cout<<endl<<"Knight rised shield on 5 hits"<<endl;
    status[0]=true;
    status_cont[0]=5;
}


void knight::skill2(vector<Creature*>,vector<Creature*>)
{
    cout<<endl<<"Knight uses Aggression on 3 turns"<<endl;
    status[1]=true;
    status_cont[1]=3;
}


knight::~knight()
{

}

