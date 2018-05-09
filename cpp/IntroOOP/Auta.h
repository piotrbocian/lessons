#pragma once

#include <string>
using namespace std;

enum class TypSilnika
{
    Diesel,
    Benzyna,
    Hybryda,
    Elektryczny,
};

class Auto
{
public:
    int pojemnoscSilnika;
    int moc;
    double cena;
    TypSilnika typSilnika;
    string vin;
};



class Audi : public Auto
{

};

class Ford : public Auto
{

};




class VW : public Auto
{
public:
    string model;
    bool trybDiagnostyczny;

protected:
    static int licznikProdukcji;
};

int VW::licznikProdukcji = 0;

class Golf : public VW
{
public:

    Golf()
    {
        typSilnika = TypSilnika::Benzyna;
        pojemnoscSilnika = 1600;
        vin = "VWG" + to_string(licznikProdukcji);
        licznikProdukcji++;
    }
};

class Passat : public VW
{
public:

    Passat()
    {
        typSilnika = TypSilnika::Diesel;
        pojemnoscSilnika = 2500;
        vin = "VWP" + to_string(licznikProdukcji);
        licznikProdukcji++;
    }

};



void program_auta()
{
    Audi A4;
    Audi A6;

    Ford Focus;
    Ford Mondeo;

    VW golf;
    golf.model = "Golf";
    golf.moc = 120;
    golf.pojemnoscSilnika = 1600;
    golf.typSilnika = TypSilnika::Diesel;

    VW passat{ "Passat", TypSilnika::Benzyna, 2000, 150 };

    VW auta[10] = {
        Golf(),
        Golf(),
        Golf(),
        Passat(),
    };
}