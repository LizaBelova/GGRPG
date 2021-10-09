#include "goblin.h"

goblin::goblin()
{
    set_name("Goblin");
    set_hp(120);
    set_max_hp(120);
    set_def(50);
    set_atk(50);
    set_max_atk(60);
    set_mana(0);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}



void goblin::skill1(vector<Creature*> heroes,vector<Creature*> monsters)
{
    cout<<"Goblin in Panic"<<endl;
    int damage=get_atk();
    int target1=rand()%monsters.size();
    int target2=rand()%heroes.size();
    int choise=rand()%2;
    if(choise==0){
        if(monsters[target1]->get_def()>0){
            monsters[target1]->set_hp(-damage/2);
            monsters[target1]->set_def(-damage/2);
            cout<<monsters[target1]->get_name()<<" get "<<damage<<" damage,"<<damage/2<<" to HP and DEF"<<endl;
            if(monsters[target1]->get_def()<0) monsters[target1]->set_def(abs(monsters[target1]->get_def()));
        }
        else {
            monsters[target1]->set_hp(-damage);
            cout<<monsters[target1]->get_name()<<" get "<<damage<<" damage to HP"<<endl;
        }
        if(monsters[target1]->get_hp()<1){
            monsters[target1]->set_hp(abs(monsters[target1]->get_hp()));
            monsters[target1]->set_status(2,true);
        }
    }
    if(choise==1){
        if(heroes[target2]->get_name()=="Knight" && heroes[target2]->get_status(0)==true){
            cout<<"Goblin hit Knight, But Knight raise the shield"<<endl;
            heroes[target2]->set_status_cont(0,-1);
            if(heroes[target2]->get_status_cont(0)==0) heroes[target2]->set_status(0,false);
            return;
        }
        if(heroes[target2]->get_def()>0){
            heroes[target2]->set_hp(-damage/2);
            heroes[target2]->set_def(-damage/2);
            cout<<heroes[target2]->get_name()<<" deal "<<damage<<" damage,"<<damage/2<<" to HP and DEF"<<endl;
            if(heroes[target2]->get_def()<0) heroes[target2]->set_def(abs(heroes[target2]->get_def()));
        }
        else {
            heroes[target2]->set_hp(-damage);
            cout<<heroes[target2]->get_name()<<" deal "<<damage<<" damage to HP"<<endl;
        }
        if(heroes[target2]->get_hp()<1){
            heroes[target2]->set_hp(abs(heroes[target2]->get_hp()));
            heroes[target2]->set_status(2,true);
        }
    }

}

void goblin::skill2(vector<Creature*> heroes,vector<Creature*>)
{
    int damage=get_atk()+get_atk()*25/100;
    int target1=rand()%heroes.size();
    cout<<"Goblin threw his club in "<<heroes[target1]->get_name()<<". Goblin damage decreased."<<endl;
    set_status(1,true);
    int new_atk=get_atk()*75/100;
    int new_max_atk=get_max_atk()*75/100;
    set_atk(-get_atk()+new_atk);
    set_max_atk(-get_max_atk()+new_max_atk);
    for(int i=0;i<heroes.size();i++){
        if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {target1=i; break;}
    }
    if(heroes[target1]->get_name()=="Knight" && heroes[target1]->get_status(0)==true){
        cout<<"But Knight raise the shield"<<endl;
        heroes[target1]->set_status_cont(0,-1);
        if(heroes[target1]->get_status_cont(0)==0) heroes[target1]->set_status(0,false);
        return;
    }
    if(heroes[target1]->get_def()>0){
        heroes[target1]->set_hp(-damage/2);
        heroes[target1]->set_def(-damage/2);
        cout<<heroes[target1]->get_name()<<" get "<<damage<<" damage,"<<damage/2<<" to HP and DEF"<<endl;
        if(heroes[target1]->get_def()<0) heroes[target1]->set_def(abs(heroes[target1]->get_def()));
    }
    else {
        heroes[target1]->set_hp(-damage);
        cout<<heroes[target1]->get_name()<<" get "<<damage<<" damage to HP"<<endl;
    }
    if(heroes[target1]->get_hp()<1){
        heroes[target1]->set_hp(abs(heroes[target1]->get_hp()));
        heroes[target1]->set_status(2,true);
    }
}


goblin::~goblin()
{

}

