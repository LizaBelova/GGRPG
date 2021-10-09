#include "priest.h"

priest::priest()
{
    set_name("Priest");
    set_hp(200);
    set_max_hp(200);
    set_def(100);
    set_atk(20);
    set_mana(700);
    skill_name1="Healing (50)";
    skill_name2="Buff/Debuff (50)";
    skill1_mana=50;
    skill2_mana=50;
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}


void priest::skill1(vector<Creature*> heroes,vector<Creature*>)
{
    int num;
    int chance=rand()%3;
    cout<<"Choose ally"<<endl<<"Select:  ";
    cin>>num;
    if(heroes[num-1]->get_max_hp()-heroes[num-1]->get_hp()<100) {
        cout<<endl<<heroes[num-1]->get_name()<<" restore "<<heroes[num-1]->get_max_hp()-heroes[num-1]->get_hp()<<" HP";
        heroes[num-1]->set_hp(heroes[num-1]->get_max_hp()-heroes[num-1]->get_hp());
        if(heroes[num-1]->get_name()=="Knight") {
            cout<<" and 50 DEF"<<endl;
            heroes[num-1]->set_def(50);
        }else{
            cout<<" and 25 DEF"<<endl;
            heroes[num-1]->set_def(25);
        }
    }
    else {
        cout<<endl<<heroes[num-1]->get_name()<<" restore 100 HP";
        heroes[num-1]->set_hp(100);
        if(heroes[num-1]->get_name()=="Knight") {
            cout<<" and 50 DEF"<<endl;
            heroes[num-1]->set_def(50);
        }else{
            cout<<" and 25 DEF"<<endl;
            heroes[num-1]->set_def(25);
        }
    }
    for(int i=4;i<8;i++){
        heroes[num-1]->set_status(i,false);
        heroes[num-1]->set_status_cont(i,-heroes[num-1]->get_status_cont(i));
    }
    if(chance==2){
        cout<<"Extra heal"<<endl;
        for(int i=0;i<heroes.size();i++){
            if(i!=num-1){
                if(heroes[i]->get_max_hp()-heroes[i]->get_hp()<100) {
                    cout<<heroes[i]->get_name()<<" restore "<<heroes[i]->get_max_hp()-heroes[i]->get_hp()<<" HP";
                    heroes[i]->set_hp(heroes[i]->get_max_hp()-heroes[i]->get_hp());
                    if(heroes[i]->get_name()=="Knight") {
                        cout<<" and 50 DEF"<<endl;
                        heroes[i]->set_def(50);
                    }else{
                        cout<<" and 25 DEF"<<endl;
                        heroes[i]->set_def(25);
                    }
                }
                else {
                    cout<<heroes[i]->get_name()<<" restore 100 HP";
                    heroes[i]->set_hp(100);
                    if(heroes[i]->get_name()=="Knight") {
                        heroes[i]->set_def(50);
                        cout<<" and 50 DEF"<<endl;

                    }else{
                        heroes[i]->set_def(25);
                        cout<<" and 25 DEF"<<endl;
                    }
                }
                for(int j=4;j<8;j++){
                    heroes[i]->set_status(j,false);
                    heroes[i]->set_status_cont(j,-heroes[i]->get_status_cont(j));
                }
            }
        }
    }
}



void priest::skill2(vector<Creature*> heroes,vector<Creature*> monsters)
{
    int num;
    int tar;
    cout<<"Choose:"<<endl<<"1. Buff"<<endl<<"2. Debuff"<<endl<<"Select: ";
    cin>>num;
    switch (num) {
    case 1:
        cout<<endl<<"Choose target"<<endl<<"Select: ";
        cin>>tar;
        heroes[tar-1]->set_atk(50);
        heroes[tar-1]->set_status(3,true);
        heroes[tar-1]->set_status_cont(3,1);
        cout<<endl<<heroes[tar-1]->get_name()<<" get +50 ATK on 1 turn"<<endl;
        break;
    case 2:
        cout<<endl<<"Choose target"<<endl<<"Select: ";
        cin>>tar;
        if(monsters[tar-1]->get_atk()<50) monsters[tar-1]->set_atk(-monsters[tar-1]->get_atk()); else
        monsters[tar-1]->set_atk(-50);
        cout<<endl<<monsters[tar-1]->get_name()<<" get -50 ATK on 1 turn"<<endl;
        monsters[tar-1]->set_status(4,true);
        monsters[tar-1]->set_status_cont(4,1);
        break;
    default:
        break;
    }
}

priest::~priest()
{

}

