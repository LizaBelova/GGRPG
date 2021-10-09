#include "rogue.h"

rogue::rogue()
{
    set_name("Rogue");
    set_hp(300);
    set_max_hp(300);
    set_def(100);
    set_atk(120);
    set_mana(200);
    skill_name1="Backstab (50)";
    skill_name2="Pure hit (30)";
    skill1_mana=50;
    skill2_mana=30;
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}


void rogue::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    int target;
    cout<<"Choose monster: ";
    cin>>target;

    if(monsters[target-1]->get_name()=="Blood Dragon" || monsters[target-1]->get_name()=="Golem"){
        cout<<"You can't use Backstab on bosses"<<endl;
        return;
    }
    cout<<endl<<"You kill "<<monsters[target-1]->get_name()<<endl;
    monsters[target-1]->set_status(2,true);
    status[0]=true;

}

void rogue::skill2(vector<Creature *>, vector<Creature *> monsters)
{
    int target;
    cout<<"Choose monster: ";
    cin>>target;

    cout<<endl<<monsters[target-1]->get_name()<<" get "<<get_atk()*0.75<<" pure damage to HP"<<endl;
    monsters[target-1]->set_hp(-get_atk()*0.75);
    monsters[target-1]->set_status(6,true);
    monsters[target-1]->set_status_cont(6,3-monsters[target-1]->get_status_cont(6));
    if(monsters[target-1]->get_hp()<1){
        monsters[target-1]->set_status(2,true);
    }
}

rogue::~rogue()
{

}
