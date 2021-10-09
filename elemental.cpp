#include "elemental.h"

elemental::elemental()
{
    set_name("Elemental");
    set_hp(100);
    set_max_hp(100);
    set_def(130);
    set_atk(85);
    set_max_atk(85);
    set_mana(0);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}

elemental::~elemental()
{

}

void elemental::skill1(vector<Creature *> heroes, vector<Creature *>)
{
    int damage;
    int target;
    int count=0;
    int agr=0;
    cout<<"Elemental uses Firestorm"<<endl;
    while(count<2){
        target=rand()%heroes.size();
        damage=20+rand()%31;
        for(int i=0;i<heroes.size();i++){
            if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1) && agr==0) {target=i; agr++; break;}
        }
        if(heroes[target]->get_name()=="Knight" && heroes[target]->get_status(0)==true){
            cout<<"But Knight raise the shield"<<endl;
            heroes[target]->set_status_cont(0,-1);
            if(heroes[target]->get_status_cont(0)==0) heroes[target]->set_status(0,false);
            return;
        }
        if(heroes[target]->get_def()>0){
            heroes[target]->set_hp(-damage/2);
            heroes[target]->set_def(-damage/2);
            cout<<heroes[target]->get_name()<<" get "<<damage<<" damage,"<<damage/2<<" to HP and DEF"<<endl;
            if(heroes[target]->get_def()<0) heroes[target]->set_def(abs(heroes[target]->get_def()));
        }
        else {
            heroes[target]->set_hp(-damage);
            cout<<heroes[target]->get_name()<<" get "<<damage<<" damage to HP"<<endl;
        }
        heroes[target]->set_status(5,true);
        heroes[target]->set_status_cont(5,3-heroes[target]->get_status_cont(5));
        if(heroes[target]->get_hp()<1){
            heroes[target]->set_hp(abs(heroes[target]->get_hp()));
            heroes[target]->set_status(2,true);
        }
        count++;

    }
}

void elemental::skill2(vector<Creature *> heroes, vector<Creature *>)
{
    int target=rand()%heroes.size();
    for(int i=0;i<heroes.size();i++){
        if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {target=i; break;}
    }
    if(heroes[target]->get_name()=="Knight" && heroes[target]->get_status(0)==true){
        cout<<"Elemental uses Frostbalt, But Knight raise the shield"<<endl;
        heroes[target]->set_status_cont(0,-1);
        if(heroes[target]->get_status_cont(0)==0) heroes[target]->set_status(0,false);
        return;
    }
    cout<<"Elemental uses Frostbolt on "<<heroes[target]->get_name()<<" and imposes Freeze"<<endl;
    heroes[target]->set_status(7,true);
    heroes[target]->set_status_cont(7,1-heroes[target]->get_status_cont(7));
}
