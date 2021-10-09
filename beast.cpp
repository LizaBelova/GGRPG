#include "beast.h"

beast::beast()
{
    set_name("Beast");
    set_hp(1000);
    set_max_hp(1000);
    set_def(0);
    set_atk(110);
    set_mana(80);
    skill_name1="Tripple hit (15)";
    skill_name2="Break the shield (15)";
    skill1_mana=15;
    skill2_mana=15;
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}



void beast::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    int target;
    int damage=get_atk();
    cout<<"Beast uses a Tripple hit"<<endl<<"Choose target: ";
    cin>>target;
    if(monsters[target-1]->get_def()>0){
        monsters[target-1]->set_hp(-damage/2);
        monsters[target-1]->set_def(-damage/2);
        cout<<monsters[target-1]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
        if(monsters[target-1]->get_def()<0) monsters[target-1]->set_def(abs(monsters[target-1]->get_def()));
    }
    else {
        monsters[target-1]->set_hp(-damage);
        cout<<monsters[target-1]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
    }
    if(monsters[target-1]->get_hp()<1){
        monsters[target-1]->set_hp(abs(monsters[target-1]->get_hp()));
        monsters[target-1]->set_status(2,true);

    }
    if(target-2>=0){
        if(monsters[target-2]->get_def()>0){
            monsters[target-2]->set_hp(-damage/2);
            monsters[target-2]->set_def(-damage/2);
            cout<<monsters[target-2]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
            if(monsters[target-2]->get_def()<0) monsters[target-2]->set_def(abs(monsters[target-2]->get_def()));
        }
        else {
            monsters[target-2]->set_hp(-damage);
            cout<<monsters[target-2]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
        }
        if(monsters[target-2]->get_hp()<1){
            monsters[target-2]->set_hp(abs(monsters[target-2]->get_hp()));
            monsters[target-2]->set_status(2,true);

        }
    }

    if(target<monsters.size()){
        if(monsters[target]->get_def()>0){
            monsters[target]->set_hp(-damage/2);
            monsters[target]->set_def(-damage/2);
            cout<<monsters[target]->get_name()<<" get "<<damage<<" damage, "<<damage/2<<" on HP and DEF"<<endl;
            if(monsters[target]->get_def()<0) monsters[target]->set_def(abs(monsters[target]->get_def()));
        }
        else {
            monsters[target]->set_hp(-damage);
            cout<<monsters[target]->get_name()<<" get "<<damage<<" damage on HP"<<endl;
        }
        if(monsters[target]->get_hp()<1){
            monsters[target]->set_hp(abs(monsters[target]->get_hp()));
            monsters[target]->set_status(2,true);

        }
    }

}

void beast::skill2(vector<Creature *>, vector<Creature *> monsters)
{
    int target;
    int damage=get_atk();
    cout<<"Beast Break Shield"<<endl<<"Choose target: ";
    cin>>target;
    if(monsters[target-1]->get_def()<1) cout<<endl<<"no DEF"<<endl;
    if(monsters[target-1]->get_def()>0){
        monsters[target-1]->set_def(-damage);
        cout<<monsters[target-1]->get_name()<<" get "<<damage<<" damage to DEF"<<endl;
        if(monsters[target-1]->get_def()<1) monsters[target-1]->set_def(abs(monsters[target-1]->get_def()));
    }

}


beast::~beast()
{

}
