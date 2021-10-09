#include "arena.h"

arena::arena()
{
}

void arena::wave(int unsigned dif)
{
    int unsigned cr1;
    int unsigned cr2;
    int unsigned cr3;
    if(dif==0){
        cr1=2+rand()%3;
        cr2=1+rand()%3;
        while(monsters.size()<cr1)
            monsters.push_back(new spider);
        while(monsters.size()<cr1+cr2)
            monsters.push_back(new goblin);
    }
    if(dif==1){
        cr1=2+rand()%2;
        cr2=1+rand()%2;
        cr3=1+rand()%2;
        while(monsters.size()<cr1)
            monsters.push_back(new goblin);
        while(monsters.size()<cr1+cr2)
            monsters.push_back(new ogre);
        while(monsters.size()<cr1+cr2+cr3)
            monsters.push_back(new shaman);
    }
    if(dif==2){
        cr1=1+rand()%3;
        cr2=2+rand()%3;
        while(monsters.size()<cr1)
            monsters.push_back(new ogre);
        while(monsters.size()<cr1+cr2)
            monsters.push_back(new elemental);


    }
    if(dif==3){
        monsters.push_back(new elknight);
        monsters.push_back(new elarcher);
        monsters.push_back(new elmage);
    }
    if(dif==4){
        monsters.push_back(new dragon);
    }
}

void arena::hero_squad()
{
    char n;
    int pos;
    string ans="Knight Priest Mage Rogue Archer Beast";
    while(heroes.size()<4){
        cout<<"You'r team:"<<endl;
        for(int unsigned i=0;i<heroes.size();i++)
            heroes[i]->stats();
        cout<<endl<<"Choose a hero: "<<ans<<endl<<"Select: ";

        cin>> n;
            switch (n) {
            case 'K':
                heroes.push_back(new knight);
                system("cls");
                pos=ans.find("K");
                ans.replace(pos,7,"");
                break;
            case 'P':
                heroes.push_back(new priest);
                system("cls");
                pos=ans.find("P");
                ans.replace(pos,7,"");
                break;
            case 'M':
                heroes.push_back(new mage);
                system("cls");
                pos=ans.find("M");
                ans.replace(pos,5,"");
                break;
            case 'R':
                heroes.push_back(new rogue);
                system("cls");
                pos=ans.find("R");
                ans.replace(pos,6,"");
                break;
            case 'A':
                heroes.push_back(new archer);
                system("cls");
                pos=ans.find("A");
                ans.replace(pos,7,"");
                break;
            case 'B':
                heroes.push_back(new beast);
                system("cls");
                pos=ans.find("B");
                ans.replace(pos,6,"");
                break;
            default:
                break;
            }
        }
}

void arena::auto_hero_squad()
{

    heroes.push_back(new rogue);
    heroes.push_back(new archer);
    heroes.push_back(new mage);
    heroes.push_back(new priest);
    //heroes.push_back(new knight);
    //heroes.push_back(new rogue);
    //heroes.push_back(new rogue);
    //heroes.push_back(new beast);
}


void arena::death_monster(int num)
{
    if(heroes.empty()==false)
    cout<<monsters[num]->get_name()<<" died"<<endl;
    delete monsters[num];
    monsters.erase(monsters.begin()+num);
}

void arena::death_hero(int num)
{
    if(monsters.empty()==false)
    cout<<endl<<heroes[num]->get_name()<<" died"<<endl;
    delete heroes[num];
    heroes.erase(heroes.begin()+num);

}

void arena::check_hbuf(int turn)
{
    if(heroes[turn]->get_status(3)){
        heroes[turn]->set_status_cont(3,-1);
        heroes[turn]->set_atk(-50);
        if(heroes[turn]->get_status_cont(3)==0)
            heroes[turn]->set_status(3,false);
    }

    if(heroes[turn]->get_status(4)){
        heroes[turn]->set_status(4,false);
    }

}
void arena::check_mbuf(int turn)
{
    if(monsters[turn]->get_status(3)){
        monsters[turn]->set_status_cont(3,-1);
        monsters[turn]->set_atk(-50);
        if(monsters[turn]->get_status_cont(3)==0)
            monsters[turn]->set_status(3,false);
    }
    if(monsters[turn]->get_status(4)){
        monsters[turn]->set_status_cont(4,-monsters[turn]->get_status_cont(4));
        monsters[turn]->set_atk(-monsters[turn]->get_atk()+monsters[turn]->get_max_atk());
        if(monsters[turn]->get_status_cont(3)==0)
            monsters[turn]->set_status(4,false);
    }
}

void arena::check_hstatus(int num)
{
    if(heroes[num]->get_status(5)){
        if(heroes[num]->get_def()>0){
            heroes[num]->set_hp(-5);
            heroes[num]->set_def(-5);
            if(heroes[num]->get_def()<0){
                heroes[num]->set_def(abs(heroes[num]->get_def()));
            }
        }
        else heroes[num]->set_hp(-10);
        if(heroes[num]->get_hp()<1){
            heroes[num]->set_status(2,true);
        }
        heroes[num]->set_status_cont(5,-1);
        if(heroes[num]->get_status_cont(5)==0)
            heroes[num]->set_status(5,false);
    }

    if(heroes[num]->get_status(6)){
        heroes[num]->set_hp(-10);
        if(heroes[num]->get_hp()<1){
            heroes[num]->set_status(2,true);
        }
        heroes[num]->set_status_cont(6,-1);
        if(heroes[num]->get_status_cont(6)==0)
            heroes[num]->set_status(6,false);
    }
}
void arena::check_mstatus(int num)
{
    if(monsters[num]->get_status(5)){
        if(monsters[num]->get_def()>0){
            monsters[num]->set_hp(-5);
            monsters[num]->set_def(-5);
            if(monsters[num]->get_def()<0){
                monsters[num]->set_def(abs(monsters[num]->get_def()));
            }
        }
        else monsters[num]->set_hp(-10);
        if(monsters[num]->get_hp()<1){
            monsters[num]->set_status(2,true);
        }
        monsters[num]->set_status_cont(5,-1);
        if(monsters[num]->get_status_cont(5)==0)
            monsters[num]->set_status(5,false);
    }

    if(monsters[num]->get_status(6)){
        monsters[num]->set_hp(-10);
        if(monsters[num]->get_hp()<1){
            monsters[num]->set_status(2,true);
        }
        monsters[num]->set_status_cont(6,-1);
        if(monsters[num]->get_status_cont(6)==0)
            monsters[num]->set_status(6,false);
    }
}

void arena::mana_up()
{
    for(int unsigned i=0;i<heroes.size();i++){
        if(heroes[i]->get_mana()<301){
            if((heroes[i]->get_mana()*0.1)>1)
            heroes[i]->set_mana((heroes[i]->get_mana()*0.1));
            else heroes[i]->set_mana(1);
        }
    }
}

void arena::restore()
{
    cout<<"After defeating boss characters restoring power"<<endl<<endl;
    for(int unsigned i=0;i<heroes.size();i++){
        if(heroes[i]->get_max_hp()-heroes[i]->get_hp()<100) {
            cout<<heroes[i]->get_name()<<" restore "<<heroes[i]->get_max_hp()-heroes[i]->get_hp()<<" HP, 75 DEF and 50 MANA"<<endl;
            heroes[i]->set_hp(heroes[i]->get_max_hp()-heroes[i]->get_hp());
            heroes[i]->set_def(75);
            heroes[i]->set_mana(50);
        }
        else {
            cout<<heroes[i]->get_name()<<" restore 100 HP, 75 DEF and 50 MANA"<<endl;
            heroes[i]->set_hp(100);
            heroes[i]->set_def(75);
            heroes[i]->set_mana(50);
        }
    }
    cout<<endl;
}

void arena::use_hp_potion(int turn)
{
    cout<<heroes[turn]->get_name()<<" uses HP Potion"<<endl;
    if(heroes[turn]->get_max_hp()-heroes[turn]->get_hp()<100) {
        cout<<endl<<heroes[turn]->get_name()<<" restore "<<heroes[turn]->get_max_hp()-heroes[turn]->get_hp()<<" HP"<<endl;
        heroes[turn]->set_hp(heroes[turn]->get_max_hp()-heroes[turn]->get_hp());

    }
    else {
        cout<<endl<<heroes[turn]->get_name()<<" restore 100 HP"<<endl;
        heroes[turn]->set_hp(100);

    }
    for(int i=4;i<8;i++){
        heroes[turn]->set_status(i,false);
        heroes[turn]->set_status_cont(i,-heroes[turn]->get_status_cont(i));
    }
}

void arena::use_mp_potion(int turn)
{
    cout<<heroes[turn]->get_name()<<" uses Mana Potion"<<endl;
        cout<<endl<<heroes[turn]->get_name()<<" restore 100 MANA"<<endl;
        heroes[turn]->set_mana(100);

}

bool arena::m_can_cast1(int num)
{
    if(monsters[num]->get_name()=="Spider") return true;
    if(monsters[num]->get_name()=="Goblin" && monsters[num]->get_hp()<(monsters[num]->get_max_hp()*25/100)) return true;
    if(monsters[num]->get_name()=="Ogre" && monsters[num]->get_hp()<(monsters[num]->get_max_hp()*40/100)){
        for(int i=0;i<monsters.size();i++){
            if(monsters[i]->get_name()=="Goblin") return true;
        }
        return false;
    }
    if(monsters[num]->get_name()=="Shaman") return true;
    if(monsters[num]->get_name()=="Elemental") return true;
    if(monsters[num]->get_name()=="Golem") return true;
    if(monsters[num]->get_name()=="Cursed Knight") return true;
    if(monsters[num]->get_name()=="Cursed Mage") return true;
    if(monsters[num]->get_name()=="Cursed Archer") return true;
    if(monsters[num]->get_name()=="Blood Dragon") return true;
    return false;
}

bool arena::m_can_cast2(int num)
{
    if(monsters[num]->get_name()=="Spider") return true;
    if(monsters[num]->get_name()=="Goblin" && monsters[num]->get_status(1)==false) return true;
    if(monsters[num]->get_name()=="Elemental") return true;
    if(monsters[num]->get_name()=="Golem") return true;
    if(monsters[num]->get_name()=="Cursed Knight") return true;
    if(monsters[num]->get_name()=="Cursed Mage") return true;
    if(monsters[num]->get_name()=="Blood Dragon") return true;
    return false;
}


void arena::the_game()
{

    int unsigned endgame=0;
    int boss=0;
    int hp_potion=10;
    int mp_potion=10;
    hero_squad();
    system("cls");
    //cout<<"Choose level:";
    //cin>>endgame;

    //игра
    do{
        int turn=0;  //ход героев
        int mturn=0; //ход монстров
        int act;     //выбор действия
        int tar;     //выбор цели
        int choise=0;//выбор для монстров
        int rep;

        system("cls");
        cout<<"-----------------------------------------------------"<<endl;
        if(endgame==0) cout<<"        You enter the Forbidden Forest"<<endl;
        if(endgame==1) cout<<"        You enter the Dark Cave"<<endl;
        if(endgame==2) cout<<"        You enter the Destroyed Ruins"<<endl;
        if(endgame==3) cout<<"        You enter the Castle"<<endl;
        if(endgame==4) cout<<"        You are on the top of tower"<<endl;
        cout<<"-----------------------------------------------------"<<endl;

        wave(endgame);
        cout<<endl<<"You met monsters:"<<endl;
        for(unsigned int j=0;j<monsters.size();j++)
            monsters[j]->stats();

        cout<<endl<<"You'r team:"<<endl;
        for(unsigned int i=0;i<heroes.size();i++)
        heroes[i]->stats();

        cout<<endl;

        system("pause");
        system("cls");

        while(monsters.empty()==false && heroes.empty()==false){

            system("cls");
            rep=0;
            if(endgame==0) cout<<"----------------------Forest-------------------------"<<endl;
            if(endgame==1) cout<<"-----------------------Cave--------------------------"<<endl;
            if(endgame==2) cout<<"----------------------Ruins--------------------------"<<endl;
            if(endgame==3) cout<<"----------------------Castle--------------------------"<<endl;
            if(endgame==4) cout<<"----------------------Tower---------------------------"<<endl;
            if(monsters.size()>0 && (monsters[0]->get_name()=="Golem" || monsters[0]->get_name()=="Blood Dragon")){
                if(mturn==0 && turn>heroes.size()-1){
                    check_mstatus(mturn);
                }
                cout<<"                   BOSS FIGHT"<<endl;
                int dash=0;
                cout<<"<";
                while(dash<monsters[0]->get_hp()){
                    cout<<"|";
                    dash+=15;
                }
                while(dash<monsters[0]->get_max_hp()){
                    cout<<"x";
                    dash+=15;
                }
                cout<<">"<<endl<<endl;
                if(monsters[mturn]->is_die()) {
                        death_monster(mturn);
                        mturn++;
                    }
                if(monsters[0]->is_die()==false){
                    if(mturn==0 && turn>heroes.size()-1) cout<<"> "; else cout<<"1 ";
                    monsters[0]->stats();
                }
            }else{

                for(unsigned int j=0;j<monsters.size();j++){
                    if(monsters[j]->is_die()) death_monster(j);
                    if(turn>heroes.size()-1 && mturn<monsters.size() && rep==0){
                        rep++;
                        check_mstatus(mturn);
                        if(monsters[mturn]->is_die()) {
                            death_monster(mturn);
                            rep=0;
                            j--;
                            continue;
                        }
                    }
                    if(j==mturn && turn>heroes.size()-1) cout<<"> "; else cout<<j+1<<" ";
                    monsters[j]->stats();
                }
            }
            cout<<endl;
            for(unsigned int i=0;i<heroes.size();i++){
                if(heroes[i]->is_die()) death_hero(i);
                if(turn<heroes.size() && rep==0){
                    rep++;
                    check_hstatus(turn);
                    if(heroes[turn]->is_die()) {
                        death_hero(turn);
                        rep=0;
                        i--;
                        continue;
                    }
                }
                if(i==turn) cout<<"> "; else cout<<i+1<<" ";
                heroes[i]->stats();
            }
            cout<<"-----------------------------------------------------"<<endl;


            if(turn>heroes.size()-1 && mturn<monsters.size()){
                cout<<"Monster turn "<<endl;
                if(monsters[mturn]->get_status(7)){
                    cout<<endl<<monsters[mturn]->get_name()<<" can't moove, becouse he frozen"<<endl<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    monsters[mturn]->set_status_cont(7,-1);
                    if(monsters[mturn]->get_status_cont(7)==0) monsters[mturn]->set_status(7,false);
                    mturn++;
                    system("pause");
                    continue;
                }else{

                    tar=((rand()%15)+(rand()%10))%heroes.size();
                    int perm1=0;
                    int perm2=0;

                    do{
                    choise=(((rand()%100)+(rand()%100))/2)%5;
                    if(choise==1 || choise==2) choise=0;
                    if(choise==3){
                        if(m_can_cast1(mturn)){
                            perm1=1;
                            choise=1;
                        }
                    }
                    if(choise==4){
                        if(m_can_cast2(mturn)){
                            perm2=1;
                            choise=2;
                        }
                    }
                    }while(choise!=0 && perm1==0 && perm2==0);
                    switch (choise) {
                    case 0:
                        for(unsigned int i=0;i<heroes.size();i++){
                            if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) {tar=i; break;}
                        }
                        if(heroes[tar]->get_name()=="Knight" && heroes[tar]->get_status(0)){
                            cout<<monsters[mturn]->get_name()<<" vs Knight"<<endl<<endl<<"Knight Raise the shield on "<<heroes[tar]->get_status_cont(0)<<" hits"<<endl;
                            heroes[tar]->update_skill1();
                        }
                        else monsters[mturn]->attack(heroes[tar]);
                        mturn++;
                        break;
                    case 1:
                        monsters[mturn]->skill1(heroes,monsters);
                        mturn++;
                        break;
                    case 2:
                        monsters[mturn]->skill2(heroes,monsters);
                        mturn++;
                        break;
                    default:
                        break;
                    }
                    for(int i=0;i<heroes.size();i++){
                        if(heroes[i]->is_die()) {
                            death_hero(i);
                            i--;
                        }
                    }
                    for(int i=0;i<monsters.size();i++){
                        if(monsters[i]->is_die()) {
                            death_monster(i);
                            if(i<mturn) mturn--;
                            i--;
                        }
                    }

                    if(monsters.empty()==false && mturn>0) check_mbuf(mturn-1);

                }
            }


            if(turn<heroes.size()){
                if(heroes[turn]->get_status(7)){
                    cout<<endl<<heroes[turn]->get_name()<<" can't moove, becouse he frozen"<<endl<<endl;
                    system("pause");
                    heroes[turn]->set_status_cont(7,-1);
                    if(heroes[turn]->get_status_cont(7)==0) heroes[turn]->set_status(7,false);
                    turn++;
                    continue;
                }
                cout<<"Select action for: "<<heroes[turn]->get_name()<<endl;
                cout<<"1. Attack"<<endl;
                cout<<"2. Defend"<<endl;
                cout<<"3. Skill 1: "<<heroes[turn]->get_skill_name(1)<<endl;
                cout<<"4. Skill 2: "<<heroes[turn]->get_skill_name(2)<<endl;
                cout<<"5. Use HP Potion: "<<hp_potion<<endl;
                cout<<"6. Use Mana Potion: "<<mp_potion<<endl;
                cout<<"Select:";
                cin>>act;
                switch (act) {
                case 1:
                    cout<<"Choose target"<<endl<<"Select:";
                    cin>>tar;
                    if(tar>monsters.size()-1) tar=monsters.size();//если цели нет, то ударит последнего
                    heroes[turn]->attack(monsters[tar-1]);
                    if(monsters[tar-1]->is_die()) death_monster(tar-1);
                    if(heroes[turn]->is_die()) {
                        death_hero(turn);
                        break;
                    }
                    turn++;
                    if(heroes.empty()==false && turn>0) check_hbuf(turn-1);
                    break;
                case 2:
                    heroes[turn]->defend();
                    turn++;
                    if(heroes.empty()==false && turn>0) check_hbuf(turn-1);
                    break;
                case 3:
                    if(heroes[turn]->can_cast(heroes[turn]->get_skill_mana(1))==false){
                        break;
                    }
                    if(heroes[turn]->get_name()=="Rogue" && heroes[turn]->get_status(0))
                    {
                        cout<<"Can't use bachstab twice in wave"<<endl;
                        break;
                    }
                    heroes[turn]->skill1(heroes,monsters);
                    heroes[turn]->set_mana(-(heroes[turn]->get_skill_mana(1)));
                    for(int unsigned j=0;j<monsters.size();j++){
                        if(monsters[j]->is_die()) {
                            death_monster(j);
                            j--;
                        }
                    }

                    turn++;
                    if(heroes.empty()==false && turn>0) check_hbuf(turn-1);
                    break;
                case 4:
                    if(heroes[turn]->can_cast(heroes[turn]->get_skill_mana(2))==false){
                        break;
                    }

                    heroes[turn]->skill2(heroes,monsters);
                    heroes[turn]->set_mana(-(heroes[turn]->get_skill_mana(2)));
                    for(int unsigned j=0;j<monsters.size();j++){
                        if(monsters[j]->is_die()) {
                            death_monster(j);
                            j--;
                        }
                    }
                    turn++;
                    if(heroes.empty()==false && turn>0) check_hbuf(turn-1);
                    break;
                case 5:
                    if(hp_potion>0) {
                        use_hp_potion(turn);
                        hp_potion--;
                    }
                    else cout<<"HP Potion ended"<<endl;
                    break;
                case 6:
                    if(mp_potion>0) {
                        use_mp_potion(turn);
                        mp_potion--;
                    }
                    else cout<<"Mana Potion ended"<<endl;
                    break;
                default:
                    break;
                }

            }

            cout<<"-----------------------------------------------------"<<endl;



            system("pause");
            if(turn>heroes.size()-1 && mturn>monsters.size()-1){
                turn=0;
                mturn=0;
                mana_up();
                for(int i=0;i<heroes.size();i++){
                    if(heroes[i]->get_name()=="Knight" && heroes[i]->get_status(1)) heroes[i]->update_skill2(); //скилл на ходы
                    break;
                }
            }
            if(endgame==2 && monsters.empty() && boss<1){
                system("cls");
                cout<<"Prepare for battle"<<endl<<endl;
                system("pause");
                system("cls");
                monsters.push_back(new golem);
                boss++;
                turn=0;
            }
            if(endgame==2 && monsters.empty() && boss==1){
                system("cls");
                restore();
                system("pause");
            }
        }
        for(int k=0;k<heroes.size();k++){
            heroes[k]->update_status();
        }
        endgame++;
    }while(endgame<5 && heroes.empty()==false);
        if(heroes.empty()==false){

            for(int j=0;j<heroes.size();j++){
                death_hero(j);
                j--;
            }
            system("cls");
            cout<<"-------------------------------------------"<<endl;
            cout<<"Heroes defeat all monsters."<<endl<<"Congratulations. You win"<<endl;
            cout<<"-------------------------------------------"<<endl;
            system("pause");
        }else{
            system("cls");
            cout<<"YOU DIED"<<endl;
            for(int j=0;j<monsters.size();j++){
                death_monster(j);
                j--;
            }
            cout<<endl<<"Try again";
            system("pause");
        }

}




