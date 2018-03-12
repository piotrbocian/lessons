// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
#include <string>

using namespace std;


void password(void)
{
    char buff[8];
    char tempbuff[8];
    int pass = 0;

    cout << "\n Zapisz haslo, 1-8 znakow : \n";
    cin >> buff;

    cout << "\n Podaj haslo dostepu: \n";
    cin >> tempbuff;

    if (strcmp(tempbuff, buff))
    {
        cout << "\n Bledne haslo! \n";

    }
    else
    {
        cout << "\n Prawidlowe haslo \n";
        pass = 1;
    }

    if (pass)
    {
        /* Now Give root or admin rights to user*/
        cout << "\n Przyznano dostep do zasobow! \n";
    }

}

int main()
{
    // string -------------------------------------
    cout << "Podaj swoje imie: ";
    string imie;
    cin >> imie;
    cout << imie << endl;

    // C-strings
    char c_tekst[] = "tekst w C";
    cout << c_tekst << ", sizeof = " << sizeof(c_tekst) << ", length = " << strlen(c_tekst) << endl;
    char c_tekst2[] = { 't', 'e', 'k', 's', 't', ' ', 'w', ' ', 'C', 0 }; // NULL terminator!

                                                                          /*
                                                                          char input1[10];
                                                                          char input2[] = " jest super!";
                                                                          cin >> input1;
                                                                          cout << input1 << input2 << endl;
                                                                          */

                                                                          // using pointer operator
    const char *p_tekst = "inny tekst w C";

    {
        char imie_nazwisko[100];
        char imie[] = "Piotr";
        char nazwisko[] = "Bocian";

        //strcat(imie_nazwisko, imie);
        //strcat(imie_nazwisko, nazwisko);

        //strcmp()
        //strlen()
        //strcpy()
    }

    {
        // std::strings
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


    {
        int a = 5;
        int *b = &a;

        cout << "a = " << a << ", &a = " << &a << endl;
        cout << "*b = " << *b << ", b = " << b << endl;

        *b = 10;
    }

    {
        int *aa = new int(5);
        delete aa;
    }

    // TODO - jak pokazać że trzeba uważać na a?
    // czas życia obiektów
    int *p_a;
    int *p_b;
    {
        int a = 5;
        p_a = &a;
        p_b = new int(7);

        cout << "p_a = " << p_a << ", *p_a = " << *p_a << endl;
        cout << "p_b = " << p_b << ", *p_b = " << *p_b << endl;
    }
    cout << "p_a = " << p_a << ", *p_a = " << *p_a << endl;
    cout << "p_b = " << p_b << ", *p_b = " << *p_b << endl;

    // alokowanie dynamicznych tablic
    {
        // dla przypomnienia - statyczna tablica
        int statyczna[100];

        // tablica dynamiczna alokowana - 
        // rozmiar może być podany w trakcie działania programu
        int n = 100;
        int *dynamiczna = new int[100];
        // zwróć uwagę na różnicę:
        int *tablica            = new int[100];
        int *pojedyncza_zmienna = new int(100);

        // taka tablica MUSI zostać zwolniona kiedy przestaje być potrzebna
        // w C++ nie ma Garbage Collectora!!!
        delete[] dynamiczna;
    }
    
    // sprawdz ile maksymalnie pamięci uda się zaalokować w środowisku x86 (32 bity)
    for (int i = 1; ; i++)
    {
        new char[1024*1024];
        cout << i << " MB!" << endl;
    }
    // Zadanie
    // Vector-Sort raz jeszcze
    // https://www.hackerrank.com/challenges/vector-sort/problem
    // Tylko tym razem zamiast std::vector prosze uzyc dynamicznej tablicy (new int[])

    password();

    // zadanie
    // https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem


    // zadanie2
    // napisz program ktory policzy litery w slowie
    // C++11
    string s = "konstantynopolitanczykowianeczka";
    int znaki[128] = { 0 };
    for (char c : s)
    {
        znaki[c]++;
    }
    for (char i = 32; i<127; i++)    // !! uwaga na przekroczenie zakresu
    {
        if (znaki[i] > 0)
        {
            cout << i << ": " << znaki[i] << endl;
        }
    }


    return 0;
}

