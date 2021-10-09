#include <QCoreApplication>
#include <iostream>
#include "arena.h"
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int select;
    arena dungeon;
    wchar_t title[] = L"GG RPG";
    SetConsoleTitle(title);
    int gg=1;
    do{
        system("cls");
        srand(time(NULL));

        dungeon.the_game();
    }while(gg=1);
    return a.exec();
}
