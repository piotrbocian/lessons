// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include <string>

using namespace std;

// funkcja ktory modyfikuje swoj parametr - implementacja na wskazniku
void zwieksz_o_100(int *a)
{
    *a += 100;
}

// dla porownania wersja z referencja (zalecana!)
void zwieksz_o_100(int &a)
{
    a += 100;
}


int main(int argc, char *argv[])
{
    // deklarujemy wskaznik 'p_a' jako zmienna pokazujaca na adres pamieci pod ktorym jest zmienna 'a'
    {
        int a = 5;
        int b = 7;
        int *p = &a;

        cout << "a = " << a << ", &a = " << &a << endl;
        cout << "p = " << p << endl;

        // aby odczytac wartosc obiektu wskazywanego
        cout << "*p = " << *p << endl;

        // aby zapisac wartosc obiektu wskazywanego
        *p = b;

        // aby przestawic wskaznik na inny obiekt
        p = &b;

        // ile teraz wynosi a, b, *p?
        a += 2;
        b += 1;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "*p = " << *p << endl;
    }

    // porownanie wskaznikow
    {
        // zainicjuj dwie takie same zmienne
        int a, b;
        a = b = 1;

        // ustaw na nie wskazniki
        int *p_a = &a;
        int *p_b = &b;

        // sprawdz czy zmienne sa takie same
        if (a == b)
        {
            cout << "a == b" << endl;
        }
        else
        {
            cout << "a = " << a << ", b = " << b << endl;
        }

        // sprawdz czy wskazniki sa takie same
        if (p_a == p_b)
        {
            cout << "p_a == p_b" << endl;
        }
        else
        {
            cout << "p_a = " << p_a << ", p_b = " << p_b << endl;
        }
    }

    // wskaŸniki const - jaka jest ró¿nica?
    {
        int a = 5;
        int b = 7;
        const int *pc_a = &a;
        int *const pc_b = &b;

        //*pc_a = 6;   // wskaŸnik na sta³¹ (const int) - nie mo¿na zmodyfikowaæ obiektu na który pokazuje
        pc_a = &b;     // ale mo¿na pokazaæ na inny obiekt

        *pc_b = 7;     // sta³y wskaŸnik - mo¿na zmodyfikowaæ obiekt
        //pc_b = &a;   // ale nie mo¿na zmieniæ obiektu na który pokazuje
    }

    // Zastosowanie nr 1 - funkcje modyfikujace parametry
    // UWAGA!
    // przekazywanie parametrow przez wskazniki pochodzi jeszcze z jezyka C
    // C++ zaleca referencje jako bezpieczniejszy sposob
    {
        int a = 2;
        cout << "a = " << a << endl;
        zwieksz_o_100(&a);
        cout << "a = " << a << endl;
    }


    // Zastosowanie nr 2 - poruszanie sie po tablicach
    {
        cout << "na podstawie indeksu" << endl;
        int tab[10] = { 1, 2, 3, 4 };
        for (int i = 0; i < 10; i++)
        {
            cout << i << ": " << tab[i] << endl;
        }

        cout << "przez wskaznik" << endl;
        int *p_tab = &tab[0];   // rownoznaczne z p_tab = tab
        for (int i = 0; i < 10; i++)
        {
            cout << p_tab << ": " << *p_tab << endl;
            p_tab++;    // inkrementacja wskaznika!
        }
        // dlaczego adres przeskakuje co 4?
        
        cout << "przez wskaznik na short" << endl;
        short *p_short_tab = reinterpret_cast<short*>(tab);   // rownoznaczne z p_tab = tab
        for (int i = 0; i < 10; i++)
        {
            cout << p_short_tab << ": " << *p_short_tab << endl;
            p_short_tab++;
        }
        // dlaczego adres przeskakuje o 2? dlaczego pojawily sie 0 miedzy liczbami?
    }


    // Cwiczenie
    // Czy dostep przez wskazniki jest szybszy?
    // Zadeklaruj duza tablice
    const int SIZE = 100000;
    // Wypelnij cala tablice N razy 
    const int N = 10000;
    // 1) uzywajac indeksowania []
    // 2) uzywajac przesuniecia wskaznika
    // Zmierz czas obu operacji (http://en.cppreference.com/w/cpp/chrono)




    // tablice znakow
    // wczesniej do pracy z tekstami uzywalismy obiektu std::string
    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;
    cout << imie << endl;

    // ale nie zawsze mozemy go uzyc i musimy bazowac na starszym mechanizmie:
    // C-strings
    char c_tekst[] = "tekst w C";
    cout << c_tekst << ", sizeof = " << sizeof(c_tekst) << ", length = " << strlen(c_tekst) << endl;
    char c_tekst2[] = { 't', 'e', 'k', 's', 't', ' ', 'w', ' ', 'C', 0 }; // null terminator!

    // deklaracja za pomoca wskaznika const char*
    const char *p_tekst = "inny tekst w C"; // dlaczego tutaj mus byc const?

    {
        char imie_nazwisko[100];
        char imie[] = "Piotr";
        char nazwisko[] = "Bocian";

        // nie skompiluja sie bez dyrektywy _CRT_SECURE_NO_WARNINGS
        //strcat(imie_nazwisko, imie);
        //strcat(imie_nazwisko, nazwisko);
        //strcmp()
        //strlen()
        //strcpy()
    }

    // tablica wskaznikow
    const char *miasta[] = { "Gdansk", "Gdynia", "Sopot" };

    // parametry wejsciowe programu
    {
        cout << "Liczba przekazanych argumentow: " << argc << endl;
        for (int i = 0; i < argc; i++)
        {
            cout << argv[i] << endl;
        }
    }


    // Zadanie
    // napisz program ktory policzy znaki ([a-z][A-Z][0-9]) w slowach podanych jako argumenty programu
    // (bez argumentu nr 0, ktorym jest nazwa programu)
    // np. po uruchomieniu:
    //   program.exe Jas mama
    // powinien wypisac
    // (kolejnosc znakow dowolna)
    //   jas
    //   a: 1
    //   s: 1
    //   J: 1
    //   mama
    //   a: 2
    //   m: 2

    // jeszcze raz std::strings- 
    // zalecony format do pracy z tekstem ale czasami nie mamy wyboru
    {
        std::string tekst = "tekst w C++";
        std::wstring w_tekst = L"tekst w C++";
        cout << tekst << endl;
        wcout << w_tekst << endl;

        cout << tekst << ", sizeof = " << sizeof(tekst) << ", length = " << tekst.length() << endl;

        // binary operators
        if (tekst == "tekst w C++")
        {
            cout << "takie same" << endl;
        }

        string nowy_tekst = tekst + ", ale troche inny";

        cout << tekst << endl << nowy_tekst << endl;
    }


    return 0;
}