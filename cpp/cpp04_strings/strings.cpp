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

