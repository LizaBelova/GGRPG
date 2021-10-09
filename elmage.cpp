#include "elmage.h"

elmage::elmage()
{
    set_name("Cursed Mage");
    set_hp(200);
    set_max_hp(200);
    set_def(130);
    set_atk(70);
    set_max_atk(70);
    set_mana(0);
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}

elmage::~elmage()
{

}

void elmage::skill1(vector<Creature *>, vector<Creature *> monsters)
{
    cout<<"Cursed Mage restore allies"<<endl;
    for(int unsigned i=0;i<monsters.size();i++){
        if(monsters[i]->get_max_hp()-monsters[i]->get_hp()<50) {
            cout<<monsters[i]->get_name()<<" restore "<<monsters[i]->get_max_hp()-monsters[i]->get_hp()<<" HP and 10 DEF"<<endl;
            monsters[i]->set_hp(monsters[i]->get_max_hp()-monsters[i]->get_hp());
            monsters[i]->set_def(10);
        }
        else {
            cout<<monsters[i]->get_name()<<" restore 50 HP and 10 DEF"<<endl;
            monsters[i]->set_hp(50);
            monsters[i]->set_def(10);
        }
    }
}

void elmage::skill2(vector<Creature *>heroes, vector<Creature *>)
{
    int target=rand()%heroes.size();
    for(int i=0;i<heroes.size();i++){
        if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {target=i; break;}
    }
    if(heroes[target]->get_name()=="Knight" && heroes[target]->get_status(0)==true){
        cout<<"Cursed Mage uses Frostbolt, But Knight raise the shield"<<endl;
        heroes[target]->set_status_cont(0,-1);
        if(heroes[target]->get_status_cont(0)==0) heroes[target]->set_status(0,false);
        return;
    }
    cout<<"Cursed Mage uses Frostbolt on "<<heroes[target]->get_name()<<" and imposes Freeze"<<endl;
    heroes[target]->set_status(7,true);
    heroes[target]->set_status_cont(7,1-heroes[target]->get_status_cont(7));
}
