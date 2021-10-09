#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include <QString>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

class Creature
{
protected:
    string _name;
    string skill_name1;
    string skill_name2;
    int _hp;
    int _atk;
    int _mana;
    int _def;
    int max_hp;
    int max_atk;
    int skill1_mana;
    int skill2_mana;

    bool status[8];       //0-скилл1, 1-скилл2, 2-смерть, 3-баф, 4-дебаф, 5-горение, 6-отравление, 7-заморозка
    int status_cont[8];   //длительность статусов

public:
    //Creature();
    Creature(int hp=0, int defence=0, int attack=0, int mana=0);
    Creature(const Creature &body);
    virtual ~Creature();

    string get_name() const;
    string get_skill_name(int num) const;
    int get_hp()const;
    int get_atk() const;
    int get_def() const;
    int get_mana() const;
    int get_max_hp() const;
    int get_max_atk() const;
    int get_status_cont(int num) const;
    int get_skill_mana(int num) const;

    bool get_status(int num) const;

    void stats();
    void set_name(string name);
    void set_max_hp(int value);
    void set_max_atk(int value);
    void set_hp(int value);
    void set_def(int value);
    void set_atk(int value);
    void set_mana(int value);
    void set_status(int num, bool value);
    void set_status_cont(int num, int value);

    bool is_die();
    bool can_cast(int skill_mana);

    void attack(Creature* &enemy);
    void defend();

    virtual void skill1(vector<Creature*>,vector<Creature*>)=0;
    virtual void skill2(vector<Creature*>,vector<Creature*>)=0;
    virtual void update_skill1();
    virtual void update_skill2();
    virtual void update_status();

};

#endif // CREATURE_H
