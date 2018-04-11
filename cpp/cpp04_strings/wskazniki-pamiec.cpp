// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include <ctime>

using namespace std;

class MojaStruktura
{
public:
    MojaStruktura() // konstruktor
    {
        cout << "konstruktor - utworzenie MojeStruktura" << endl;
    }
    ~MojaStruktura()    // destruktor
    {
        cout << "destruktor - usuniecie MojaSturktura" << endl;
    }
};

int* lotto1();
int* lotto2();
void wypiszWyniki(int wyniki[]);

void main()
{
    // Wst�p - czas �ycia vs zakres wa�no�ci

    // co oznaczaj� poni�sze instrukcje?
    {
        int a1;             // niezainicjowana zmienna na stosie
        int a2 = 2;         // zainicjowana zmienna na stosie 
        int a3(3);          // inna forma inicjalizacji zmiennej na stosie

        int *b1;            // niezainicjowana zmienna wska�nikowa na stosie
        int *b2 = &a1;      // zainicjowana zmienna wska�nikowa na stosie

        new int;            // niezainicjowana zmienna int na stercie
        new int();          // zainicjowana zerem zmienna int na stercie
        new int(5);         // zainicjowana zmienna int na stercie
        b1 = new int(4);    // przypisanie do zmiennej wska�nikowej adresu zmiennej ze sterty

        // W C++ mo�emy decydowa� kt�re zmienne/obiekte deklarowane s� na stosie ('stack'),
        // a kt�re na stercie ('heap').

        // czas �ycia obiekt�w na STOSIE - do ko�ca zakresu {}
        // czas �ycia obiekt�w na STERCIE - do czasu ich zwolnienia
    }

    // Czy to oznacza, �e mo�emy teraz skorzysta� z b1?
    //cout << *b1;
    // Nie- obiekt new int(4) zosta� zadeklarowany co prawda na stercie,
    // ale wska�nik do niego by� "tylko" na stosie i zosta� ju� zwolniony

    // Dla niedowiark�w - konstruktor i destruktor da zna� kiedy si� wywo�a
    {
        MojaStruktura ms;
    }

    {
        MojaStruktura * ms = new MojaStruktura();
    }

    // Do usuwania obiekt�w na stercie u�ywamy operatora delete
    {
        int *a = new int(5);
        delete a;

        // wywo�anie delete po raz drugi najprawdopodobniej spowoduje b��d pami�ci
        //delete a;

        // dlatego zawsze bezpiecznie po skasowaniu obiektu ustawi� wska�nik na nullptr
        a = nullptr;    // u�ywajmy nullptr zamiast NULL
        // teraz mo�emy kasowa� bezpiecznie bo delete na nullptr nic nie robi
        delete a;
    }

    // Wyciek pami�ci
    // Zademonstrujmy problem u�ywaj�c dw�ch zmiennych typu char
    // symbolizuj�cych baloniki z helem z cyframi '1' oraz '8'
    {
        // zadeklarujmy dwie zmienne typu int u�ywaj�c operatora new
        char *czerwony_sznurek = new char('1');
        char *zielony_sznurek = new char('8');

        cout << "*czerwony = " << *czerwony_sznurek << ", *zielony = " << *zielony_sznurek << endl;

        // teraz przepnijmy jeden wska�nik do drugiego
        zielony_sznurek = czerwony_sznurek;

        cout << "*czerwony = " << *czerwony_sznurek << ", *zielony = " << *zielony_sznurek << endl;
        delete zielony_sznurek;
        //delete czerwony_szunurek;   // czrwony pokazuje teraz na t� sam� pami�� co zielony, kt�ra zosta�a ju� zwolniona!!!
        // a pami�� po czerwonym nie zosta�a zwolniona - wyst�pi� tzw WYCIEK PAMI�CI ("MEMORY LEAK")
    }


    // alokowanie dynamicznych tablic
    {
        // dla przypomnienia - statyczna tablica
        int statyczna[100];

        // tablica dynamiczna alokowana - 
        // rozmiar mo�e by� podany w trakcie dzia�ania programu
        int *dynamiczna = new int[100];

        // zwr�� uwag� na r�nic� deklaracji tablicy vs pojedynczej zmiennej:
        int *tablica =              new int[100];
        int *pojedyncza_zmienna =   new int(100);

        // taka tablica MUSI zosta� zwolniona kiedy przestaje by� potrzebna
        // u�ywamy operatora delete[]
        delete[] dynamiczna;
    }

    // Przyklad
    // dwie funkcje zwracaj�ce tablice z wynikami lotto
    int *losowanie1 = lotto1();
    wypiszWyniki(losowanie1);
    
    int *losowanie2 = lotto2();
    wypiszWyniki(losowanie2);
    delete[] losowanie2;
    // Sprawdz wyniki. Czy obie funkcje s� poprawne?


    // Zadanie - sprawdz ile maksymalnie pami�ci uda si� zaalokowa� w trybie x86 (32 bity)
    // a ile w trybie x64?
    // Przypomnienie - a ile mo�na bylo zaalokowac na stosie?

    // Zadanie
    // Vector-Sort raz jeszcze
    // https://www.hackerrank.com/challenges/vector-sort/problem
    // Tylko tym razem zamiast std::vector prosze uzyc dynamicznej tablicy (new int[])
}

// UWAGA - funkcja jest NIEPOPRAWNA i stanowi tylko przyk�ad niepoprawnego dzia�ania programu!
int* lotto1()
{
    std::srand(std::time(nullptr));
    int wyniki[6];
    for (int i = 0; i < 6; i++)
    {
        wyniki[i] = (std::rand() % 49) + 1;
    }
    return wyniki;
}

int* lotto2()
{
    std::srand(std::time(nullptr));
    int *wyniki = new int[6];
    for (int i = 0; i < 6; i++)
    {
        wyniki[i] = (std::rand() % 49) + 1;
    }
    return wyniki;
}

void wypiszWyniki(int wyniki[])
{
    for (int i = 0; i < 6; i++)
    {
        cout << wyniki[i] << " ";
    }
    cout << endl;
}