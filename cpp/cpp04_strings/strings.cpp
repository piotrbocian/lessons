// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include <string>

#include <cassert>

using namespace std;


// funkcja int moze przyjmowac parametry przekazane z systemu:
// argc - liczba parametrow
// argv[] - tablica wskaznikow na parametry programu:
//   argv[0] - nazwa pliku .exe
//   argv[i] - kolejne przekazane parametry
int main(int argc, char *argv[])
{ 
    // std::string - typ do obslugi napisow w bibliotece standardowej C++
    {
        cout << "Podaj swoje imie: ";
        string imie;
        cin >> imie;
        cout << imie << endl;

        std::string tekst = "tekst w C++";
        std::wstring w_tekst = L"tekst w C++";
        cout << tekst << endl;
        wcout << w_tekst << endl;

        cout << tekst << ", sizeof = " << sizeof(tekst) << ", length = " << tekst.length() << endl;

        // porownanie napisow
        if (tekst == "tekst w C++")
        {
            cout << "takie same" << endl;
        }

        // sklejanie napisow
        string nowy_tekst = tekst + ", ale troche inny";

        cout << tekst << endl << nowy_tekst << endl;
    }

    // ale nie zawsze mozemy uzyc std::string i czasem musimy pracowac na starszym mechanizmie:
    // C-strings
    char c_tekst[] = "tekst w C";
    cout << c_tekst << ", sizeof = " << sizeof(c_tekst) << ", length = " << strlen(c_tekst) << endl;
    char c_tekst2[] = { 't', 'e', 'k', 's', 't', ' ', 'w', ' ', 'C', 0 }; // null terminator!

    // deklaracja za pomoca wskaznika const char*
    const char * const p_tekst = "inny tekst w C"; // co oznaczaj¹ 2 x const?


    // poruszanie sie po C-stringu za pomoca wskaznika...
    const char * wsk = p_tekst;
    while (*wsk != NULL)
    {
        cout << *wsk++ << "-";
    }
    cout << endl;

    // lub indeksu
    for (int i = 0; p_tekst[i] != NULL; i++)
    {
        cout << p_tekst[i] << ".";
    }
    cout << endl;

    // Tak przy okazji - co jesli siê nie zatrzymamy i bedziemy wypisywac dalej? 
    /*
    while (1)
    {
        cout << *wsk++;
    }
    */

    // operacje na C-stringach
    {
        char imie_nazwisko[100];
        char imie[] = "Piotr";
        char nazwisko[] = "Bocian";

        // porownanie dwoch napisow
        if (imie == "Piotr")
        {
            cout << "Tak, jestem " << imie << endl;
        }
        else
        {
            cout << "Nie jestem Piotr, jestem " << imie << endl;
        }

        // inne porownanie
        if (strcmp(imie, "Piotr") == 0) // porownanie "leksykalne"
        {
            cout << "Tak, jestem " << imie << endl;
        }
        else
        {
            cout << "Nie jestem Piotr, jestem " << imie << endl;
        }

        // nie skompiluja sie bez dyrektywy _CRT_SECURE_NO_WARNINGS
        //strcat(imie_nazwisko, imie);
        //strcat(imie_nazwisko, nazwisko);
        //strlen()
        //strcpy()

        // "bezpieczne" odpowiedniki
        //strcat_s(...)
        //strnlen_s(...)
        //strcpy_s(...)
    }



    // tablica wskaznikow
    const char *miasta[] = { "Gdansk", "Gdynia", "Sopot" };


    // parametry wejsciowe programu - wroc do komentarza przed funkcja main()
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


    // Zadanie
    // napisz program, który:
    // 1) poprosi u¿ytkownika o wpisanie nowego has³a i 
    // 2) dokona weryfikacji has³a:
    // - has³o powinno posiadaæ od 8 do 20 znaków
    // - co najmniej 1 ma³¹ literê
    // - co najmniej 1 du¿¹ literê
    // - co najmniej 1 cyfrê
    // - co najmniej 1 znak specjalny (ka¿dy znak nie bêd¹cy lier¹ ani cyfr¹)
    // 3) poprosi u¿ytkownika o wpisanie ponownie has³a
    // 4) poinformuje u¿ytkonika czy has³a wpisane w (1) i (3) s¹ takie same
    // !!! Funkcja weryfikuj¹ca has³o (2) powinna byæ przetestowana testami jednostkowymi!!!

    // TESTY JEDNOSTKOWE - PODSTAWY
    //#include <cassert>
    assert(2 == 2);
    //assert(2 == 1);   // ta linijka spowoduje b³¹d podczas uruchomienia
    //assert(sprawdzPoprawnoscHasla("Poprawne1!") == true);
    //assert(sprawdzPoprawnoscHasla("niepoprawne") == false);

    return 0;
}
