#pragma once

#include <iostream>
using namespace std;

class Zwierze
{
protected:
    Zwierze(int dz) : dlugoscZycia(dz)
    {

    }
    int dlugoscZycia;

public:
    int DlugoscZycia()
    {
        return dlugoscZycia;
    }
};

class Ssak : public Zwierze
{
public:
    Ssak(int dlugoscZycia) : Zwierze(dlugoscZycia)
    {

    }
    int dlugoscCiazy;
};

enum class TypWody
{
    Slodka,
    Slona
};

class Ryba : public Zwierze
{
protected:
    TypWody typWody;

public:
    Ryba(int dlugoscZycia, TypWody typWody) : Zwierze(dlugoscZycia)
    {
        this->typWody = typWody;
    }
};

class Czlowiek : public Ssak
{
public:
    Czlowiek() : Ssak(75)
    {
        dlugoscCiazy = 40;
    }

    void wypiszInformacje()
    {
        cout << "Czlowiek" << endl;
        cout << "Dlugosc zycia: " << dlugoscZycia << endl;
        cout << "Dlugosc ciazy: " << dlugoscCiazy << endl;
    }
};

class Pies : public Ssak
{
public:
    Pies() : Ssak(15)
    {
        dlugoscCiazy = 21;
    }
};


void zoo()
{
    Czlowiek ja;
    ja.DlugoscZycia();

    Czlowiek ty;
    ty.DlugoscZycia();

    Pies piesek;
    Ssak kot(18);

    Ryba nemo(5, TypWody::Slona);
    Zwierze jez;
    jez.DlugoscZycia();
}