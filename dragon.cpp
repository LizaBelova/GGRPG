#include "dragon.h"

dragon::dragon()
{
    set_name("Blood Dragon");
    set_hp(1000);
    set_max_hp(1000);
    set_def(400);
    set_atk(170);
    set_max_atk(170);
    set_mana(0);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}

dragon::~dragon()
{

}

void dragon::skill1(vector<Creature *> heroes, vector<Creature *>)
{
    int damage=get_atk()*1.25;
    int target=rand()%heroes.size();
    cout<<"Dragon uses a fire-breathing"<<endl;
    for(int i=0;i<heroes.size();i++){
        if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {target=i; break;}
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
        cout<<heroes[target]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
        if(heroes[target]->get_def()<0) heroes[target]->set_def(abs(heroes[target]->get_def()));
    }
    else {
        heroes[target]->set_hp(-damage);
        cout<<heroes[target]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
    }
    heroes[target]->set_status(5,true);
    heroes[target]->set_status_cont(5,3-heroes[target]->get_status_cont(5));
    if(heroes[target]->get_hp()<1){
        heroes[target]->set_hp(abs(heroes[target]->get_hp()));
        heroes[target]->set_status(2,true);

    }

    if(target+1<heroes.size()){
        if(heroes[target+1]->get_name()=="Knight" && heroes[target+1]->get_status(0)==true){
            cout<<"But Knight raise the shield"<<endl;
            heroes[target+1]->set_status_cont(0,-1);
            if(heroes[target+1]->get_status_cont(0)==0) heroes[target+1]->set_status(0,false);
            return;
        }
        if(heroes[target+1]->get_def()>0){
            heroes[target+1]->set_hp(-damage/2);
            heroes[target+1]->set_def(-damage/2);
            cout<<heroes[target+1]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
            if(heroes[target+1]->get_def()<0) heroes[target+1]->set_def(abs(heroes[target+1]->get_def()));
        }
        else {
            heroes[target+1]->set_hp(-damage);
            cout<<heroes[target+1]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
        }
        heroes[target]->set_status(5,true);
        heroes[target]->set_status_cont(5,3-heroes[target]->get_status_cont(5));
        if(heroes[target+1]->get_hp()<1){
            heroes[target+1]->set_hp(abs(heroes[target+1]->get_hp()));
            heroes[target+1]->set_status(2,true);

        }
    }
}

void dragon::skill2(vector<Creature *> heroes, vector<Creature *>)
{
    int target;
    int damage=get_atk()*75/100;
    target=rand()%heroes.size();
    cout<<"Dragon makes Hit the tail"<<endl;
    for(int i=0;i<heroes.size();i++){
        if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {target=i; break;}
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
        cout<<heroes[target]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
        if(heroes[target]->get_def()<0) heroes[target]->set_def(abs(heroes[target]->get_def()));
    }
    else {
        heroes[target]->set_hp(-damage);
        cout<<heroes[target]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
    }
    if(heroes[target]->get_hp()<1){
        heroes[target]->set_hp(abs(heroes[target]->get_hp()));
        heroes[target]->set_status(2,true);

    }

    if(target+1<heroes.size()){
        if(heroes[target+1]->get_name()=="Knight" && heroes[target+1]->get_status(0)==true){
            cout<<"But Knight raise the shield"<<endl;
            heroes[target+1]->set_status_cont(0,-1);
            if(heroes[target+1]->get_status_cont(0)==0) heroes[target+1]->set_status(0,false);
            return;
        }
        if(heroes[target+1]->get_def()>0){
            heroes[target+1]->set_hp(-damage/2);
            heroes[target+1]->set_def(-damage/2);
            cout<<heroes[target+1]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
            if(heroes[target+1]->get_def()<0) heroes[target+1]->set_def(abs(heroes[target+1]->get_def()));
        }
        else {
            heroes[target+1]->set_hp(-damage);
            cout<<heroes[target+1]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
        }
        if(heroes[target+1]->get_hp()<1){
            heroes[target+1]->set_hp(abs(heroes[target+1]->get_hp()));
            heroes[target+1]->set_status(2,true);

        }
        return;
    }
    if(target-1>=0){
        if(heroes[target-1]->get_name()=="Knight" && heroes[target-1]->get_status(0)==true){
            cout<<"But Knight raise the shield"<<endl;
            heroes[target-1]->set_status_cont(0,-1);
            if(heroes[target-1]->get_status_cont(0)==0) heroes[target-1]->set_status(0,false);
            return;
        }
        if(heroes[target-1]->get_def()>0){
            heroes[target-1]->set_hp(-damage/2);
            heroes[target-1]->set_def(-damage/2);
            cout<<heroes[target-1]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
            if(heroes[target-1]->get_def()<0) heroes[target-1]->set_def(abs(heroes[target-1]->get_def()));
        }
        else {
            heroes[target-1]->set_hp(-damage);
            cout<<heroes[target-1]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
        }
        if(heroes[target-1]->get_hp()<1){
            heroes[target-1]->set_hp(abs(heroes[target-1]->get_hp()));
            heroes[target-1]->set_status(2,true);

        }
    }
}

