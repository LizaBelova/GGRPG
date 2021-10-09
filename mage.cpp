#include "mage.h"

mage::mage()
{
    set_name("Mage");
    set_hp(200);
    set_max_hp(200);
    set_def(100);
    set_atk(70);
    set_mana(400);
    skill_name1="AOE Fireball (50)";
    skill_name2="Chain of lightning (30)";
    skill1_mana=50;
    skill2_mana=30;
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}


void mage::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    int damage;
    cout<<endl<<"Mage cast AOE Fireball"<<endl<<endl;
    for(int unsigned i=0;i<monsters.size();i++){
        damage=30+rand()%11;
        if(monsters[i]->get_def()>0){
            monsters[i]->set_hp(-damage/2);
            monsters[i]->set_def(-damage/2);
            cout<<monsters[i]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
            if(monsters[i]->get_def()<0) monsters[i]->set_def(abs(monsters[i]->get_def()));
        }
        else {
            monsters[i]->set_hp(-damage);
            cout<<monsters[i]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
        }
        monsters[i]->set_status(5,true);
        monsters[i]->set_status_cont(5,3-monsters[i]->get_status_cont(5));
        if(monsters[i]->get_hp()<1){
            monsters[i]->set_hp(abs(monsters[i]->get_hp()));
            monsters[i]->set_status(2,true);

        }

    }
}

void mage::skill2(vector<Creature *>, vector<Creature *> monsters)
{
    int target;
    int damage;
    int count=0;
    cout<<"Mage cast Chain of lightning"<<endl<<endl;
    while(count<3){
        target=rand()%monsters.size();
        damage=20+rand()%31;

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
        monsters[target]->set_status(5,true);
        monsters[target]->set_status_cont(5,3-monsters[target]->get_status_cont(5));
        if(monsters[target]->get_hp()<1){
            monsters[target]->set_hp(abs(monsters[target]->get_hp()));
            monsters[target]->set_status(2,true);
        }
        count++;

    }
}

mage::~mage()
{

}
