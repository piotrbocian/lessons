// cpp06_bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Bank\Bankomat.h"
// + LINKER!

int main()
{
    Bankomat bankomat;
    bankomat.wczytajKarte("1234-4567-4245-1424");
    bankomat.wysunKarte();

    bankomat.wczytajKarte("1234-4321-0987-7890");
    bankomat.wyplac(100.34);

    return 0;
}

