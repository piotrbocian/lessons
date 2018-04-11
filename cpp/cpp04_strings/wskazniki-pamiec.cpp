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
    // Wstêp - czas ¿ycia vs zakres wa¿noœci

    // co oznaczaj¹ poni¿sze instrukcje?
    {
        int a1;             // niezainicjowana zmienna na stosie
        int a2 = 2;         // zainicjowana zmienna na stosie 
        int a3(3);          // inna forma inicjalizacji zmiennej na stosie

        int *b1;            // niezainicjowana zmienna wskaŸnikowa na stosie
        int *b2 = &a1;      // zainicjowana zmienna wskaŸnikowa na stosie

        new int;            // niezainicjowana zmienna int na stercie
        new int();          // zainicjowana zerem zmienna int na stercie
        new int(5);         // zainicjowana zmienna int na stercie
        b1 = new int(4);    // przypisanie do zmiennej wskaŸnikowej adresu zmiennej ze sterty

        // W C++ mo¿emy decydowaæ które zmienne/obiekte deklarowane s¹ na stosie ('stack'),
        // a które na stercie ('heap').

        // czas ¿ycia obiektów na STOSIE - do koñca zakresu {}
        // czas ¿ycia obiektów na STERCIE - do czasu ich zwolnienia
    }

    // Czy to oznacza, ¿e mo¿emy teraz skorzystaæ z b1?
    //cout << *b1;
    // Nie- obiekt new int(4) zosta³ zadeklarowany co prawda na stercie,
    // ale wskaŸnik do niego by³ "tylko" na stosie i zosta³ ju¿ zwolniony

    // Dla niedowiarków - konstruktor i destruktor da znaæ kiedy siê wywo³a
    {
        MojaStruktura ms;
    }

    {
        MojaStruktura * ms = new MojaStruktura();
    }

    // Do usuwania obiektów na stercie u¿ywamy operatora delete
    {
        int *a = new int(5);
        delete a;

        // wywo³anie delete po raz drugi najprawdopodobniej spowoduje b³¹d pamiêci
        //delete a;

        // dlatego zawsze bezpiecznie po skasowaniu obiektu ustawiæ wskaŸnik na nullptr
        a = nullptr;    // u¿ywajmy nullptr zamiast NULL
        // teraz mo¿emy kasowaæ bezpiecznie bo delete na nullptr nic nie robi
        delete a;
    }

    // Wyciek pamiêci
    // Zademonstrujmy problem u¿ywaj¹c dwóch zmiennych typu char
    // symbolizuj¹cych baloniki z helem z cyframi '1' oraz '8'
    {
        // zadeklarujmy dwie zmienne typu int u¿ywaj¹c operatora new
        char *czerwony_sznurek = new char('1');
        char *zielony_sznurek = new char('8');

        cout << "*czerwony = " << *czerwony_sznurek << ", *zielony = " << *zielony_sznurek << endl;

        // teraz przepnijmy jeden wskaŸnik do drugiego
        zielony_sznurek = czerwony_sznurek;

        cout << "*czerwony = " << *czerwony_sznurek << ", *zielony = " << *zielony_sznurek << endl;
        delete zielony_sznurek;
        //delete czerwony_szunurek;   // czrwony pokazuje teraz na t¹ sam¹ pamiêæ co zielony, która zosta³a ju¿ zwolniona!!!
        // a pamiêæ po czerwonym nie zosta³a zwolniona - wyst¹pi³ tzw WYCIEK PAMIÊCI ("MEMORY LEAK")
    }


    // alokowanie dynamicznych tablic
    {
        // dla przypomnienia - statyczna tablica
        int statyczna[100];

        // tablica dynamiczna alokowana - 
        // rozmiar mo¿e byæ podany w trakcie dzia³ania programu
        int *dynamiczna = new int[100];

        // zwróæ uwagê na ró¿nicê deklaracji tablicy vs pojedynczej zmiennej:
        int *tablica =              new int[100];
        int *pojedyncza_zmienna =   new int(100);

        // taka tablica MUSI zostaæ zwolniona kiedy przestaje byæ potrzebna
        // u¿ywamy operatora delete[]
        delete[] dynamiczna;
    }

    // Przyklad
    // dwie funkcje zwracaj¹ce tablice z wynikami lotto
    int *losowanie1 = lotto1();
    wypiszWyniki(losowanie1);
    
    int *losowanie2 = lotto2();
    wypiszWyniki(losowanie2);
    delete[] losowanie2;
    // Sprawdz wyniki. Czy obie funkcje s¹ poprawne?


    // Zadanie - sprawdz ile maksymalnie pamiêci uda siê zaalokowaæ w trybie x86 (32 bity)
    // a ile w trybie x64?
    // Przypomnienie - a ile mo¿na bylo zaalokowac na stosie?

    // Zadanie
    // Vector-Sort raz jeszcze
    // https://www.hackerrank.com/challenges/vector-sort/problem
    // Tylko tym razem zamiast std::vector prosze uzyc dynamicznej tablicy (new int[])
}

// UWAGA - funkcja jest NIEPOPRAWNA i stanowi tylko przyk³ad niepoprawnego dzia³ania programu!
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