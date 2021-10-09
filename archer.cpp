#include "archer.h"

archer::archer()
{
    set_name("Archer");
    set_hp(200);
    set_max_hp(200);
    set_def(125);
    set_atk(100);
    set_mana(150);
    skill_name1="Random HeadShot(freeze) (30)";
    skill_name2="Double Shot (25)";
    skill1_mana=30;
    skill2_mana=25;
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}



void archer::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    int target;
    int damage=get_atk()+get_atk()*2/3;
    cout<<"Archer uses a Random Headshot"<<endl<<endl;
    target=rand()%monsters.size();

    if(monsters[target]->get_def()>0){
        monsters[target]->set_hp(-damage/2);
        monsters[target]->set_def(-damage/2);
        cout<<monsters[target]->get_name()<<" get "<<damage<<" damage,"<<damage/2<<" to HP and DEF"<<endl;
        if(monsters[target]->get_def()<0) monsters[target]->set_def(abs(monsters[target]->get_def()));
    }
    else {
        monsters[target]->set_hp(-damage);
        cout<<monsters[target]->get_name()<<" get "<<damage<<" damage to HP"<<endl;
    }
    if(monsters[target]->get_name()!="Golem" && monsters[target]->get_name()!="Blood Dragon"){
        monsters[target]->set_status(7,true);
        monsters[target]->set_status_cont(7,1-monsters[target]->get_status_cont(7));
    }
    if(monsters[target]->get_hp()<1){
        monsters[target]->set_hp(abs(monsters[target]->get_hp()));
        monsters[target]->set_status(2,true);
    }

}

void archer::skill2(vector<Creature *>, vector<Creature *> monsters)
{
    int target1;
    int target2;
    int damage=get_atk()*2/3;
    cout<<"Archer uses a double shot"<<endl<<"Choose target 1: ";
    cin>>target1;
    cout<<"Choose target 2: ";
    cin>>target2;
    if(monsters[target1-1]->get_def()>0){
        monsters[target1-1]->set_hp(-damage/2);
        monsters[target1-1]->set_def(-damage/2);
        cout<<monsters[target1-1]->get_name()<<" get "<<damage<<" damage,"<<damage/2<<" to HP and DEF"<<endl;
        if(monsters[target1-1]->get_def()<0) monsters[target1-1]->set_def(abs(monsters[target1-1]->get_def()));
    }
    else {
        monsters[target1-1]->set_hp(-damage);
        cout<<monsters[target1-1]->get_name()<<" get "<<damage<<" damage to HP"<<endl;
    }

    if(monsters[target1-1]->get_hp()<1){
        monsters[target1-1]->set_hp(abs(monsters[target1-1]->get_hp()));
        monsters[target1-1]->set_status(2,true);
    }
    if(target1!=target2 || monsters[target1-1]->is_die()==false){
        if(monsters[target2-1]->get_def()>0){
            monsters[target2-1]->set_hp(-damage/2);
            monsters[target2-1]->set_def(-damage/2);
            cout<<monsters[target2-1]->get_name()<<" get "<<damage<<" damage,"<<damage/2<<" to HP and DEF"<<endl;
            if(monsters[target2-1]->get_def()<0) monsters[target2-1]->set_def(abs(monsters[target2-1]->get_def()));
        }
        else {
            monsters[target2-1]->set_hp(-damage);
            cout<<monsters[target2-1]->get_name()<<" get "<<damage<<" damage to HP"<<endl;
        }
        if(monsters[target2-1]->get_hp()<1){
            monsters[target2-1]->set_hp(abs(monsters[target2-1]->get_hp()));
            monsters[target2-1]->set_status(2,true);
        }
    }

}

archer::~archer()
{

}
