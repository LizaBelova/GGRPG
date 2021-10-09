#include "creature.h"
#include <iostream>

using namespace std;


/*Creature::Creature()
{
    _name="creature";
    _hp=0;
    max_hp=0;
    _def=0;
    _atk=0;
    max_atk=0;
    _mana=0;

}*/

Creature::Creature(int hp, int defence, int atk_power, int mana)
{
    _name="creature";
    _hp=hp;
    max_hp=hp;
    _def=defence;
    _atk=atk_power;
    _mana=mana;
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }

}

Creature::Creature(const Creature &body)
{
    _name=body.get_name();
    _hp=body.get_hp();
    max_hp=body.get_max_hp();
    _def=body.get_def();
    _atk=body.get_atk();
    _mana=body.get_mana();
    for(int i=0;i<8;i++){
        status[i]=body.status[i];
        status_cont[i]=body.status_cont[i];
    }

}


string Creature::get_name() const
{
    return _name;
}

int Creature::get_hp() const
{
    return _hp;
}

int Creature::get_atk() const
{
    return _atk;
}

int Creature::get_def() const
{
    return _def;
}

int Creature::get_mana() const
{
    return _mana;
}

int Creature::get_max_hp() const
{
    return max_hp;
}

int Creature::get_max_atk() const
{
    return max_atk;
}

string Creature::get_skill_name(int num) const
{
   if(num==1) return skill_name1; else return skill_name2;

}

bool Creature::get_status(int num) const
{
    return status[num];
}

int Creature::get_status_cont(int num) const
{
    return status_cont[num];
}

int Creature::get_skill_mana(int num) const
{
    if(num==1) return skill1_mana; else return skill2_mana;
}


void Creature::stats()
{
    cout.setf(ios::left);
    cout.width(7);
    cout<<_name;
    cout<<" HP:";
    cout.width(4);
    cout<<_hp;
    cout<<"/";
    cout.width(4);
    cout<<max_hp;
    cout<<" DEF:";
    cout.width(4);
    cout<<_def;
    cout<<" ATK:";
    cout.width(3);
    cout<<_atk;
    if(_mana>0) {
        cout<<" MANA:";
        cout.width(5);
        cout<<_mana;
    }
    cout.unsetf(ios::left);
    if(_name=="Knight" && (status[0]==true || status[1]==true)) cout<<"| "<<status_cont[0]<<"/"<<status_cont[1];
    if(status[3]) cout<<"| Buf("<<status_cont[3]<<")";
    if(status[4]) cout<<"| Debuf("<<status_cont[4]<<")";
    if(status[5]) cout<<"| Burn("<<status_cont[5]<<")";
    if(status[6]) cout<<"| Poison("<<status_cont[6]<<")";
    if(status[7]) cout<<"| Freeze("<<status_cont[7]<<")";
    cout<<endl;
    return;

}

void Creature::set_name(string name)
{
    _name=name;
}

void Creature::set_max_hp(int value)
{
    max_hp=value;
}

void Creature::set_max_atk(int value)
{
    max_atk=value;
}

void Creature::set_hp(int value)
{
    _hp+=value;
}

void Creature::set_def(int value)
{
    _def+=value;
}

void Creature::set_atk(int value)
{
    _atk+=value;
}

void Creature::set_mana(int value)
{
    _mana+=value;
}

void Creature::set_status(int num, bool value)
{
    status[num]=value;
}

void Creature::set_status_cont(int num, int value)
{
    status_cont[num]+=value;
}


bool Creature::is_die()
{
    return status[2];
}

bool Creature::can_cast(int skill_mana)
{
    if(_mana+1>skill_mana) return true; else{
        cout<<"Not enought mana for cast"<<endl;
        return false;
    }
}


void Creature::attack(Creature *&enemy)
{
    int damage=get_atk();

    cout<<"-------------------------------------------"<<endl;
    cout<<get_name()<<" vs "<<enemy->get_name()<<endl<<endl;

    if(damage>enemy->get_def()){                                                           //если атака больше брони противника
        enemy->set_hp(-(damage-enemy->get_def()));                                         //понижаем хп противника
        cout<<">"<<enemy->get_name()<<" -"<<damage-enemy->get_def()<<" hp"<<endl;
        if(enemy->get_def()>0){
            cout<<">"<<enemy->get_name()<<" -"<<enemy->get_def()<<" defence"<<endl<<endl;
            enemy->set_def(-damage/2);                                                     //понижаем броню противника
            if(enemy->get_def()<1) enemy->set_def(abs(enemy->get_def()));
        }else cout<<endl;
    }
    else{
        enemy->set_def(-(damage)/2);                                                       //если броня противника больше нашей атаки, то понижаем броню
        cout<<">"<<enemy->get_name()<<" -"<<damage/2<<" defence"<<endl<<endl;
    }


    if(enemy->get_hp()<1){
        enemy->set_hp(abs(enemy->get_hp()));
                                    //если хп противника 0 то он умирает
        enemy->status[2]=true;
    }
}

void Creature::defend()
{
    cout<<endl<<get_name()<<" get 40 DEF"<<endl;
    set_def(40);
}

void Creature::update_skill1()
{
    status_cont[0]--;
    if(status_cont[0]<1) status[0]=false;
}

void Creature::update_skill2()
{
    status_cont[1]--;
    if(status_cont[1]<1) status[1]=false;
}

void Creature::update_status()
{
    for(int i=0;i<8;i++){
        status[i]=false;
        status_cont[i]=0;
    }
}


Creature::~Creature()
{

}
