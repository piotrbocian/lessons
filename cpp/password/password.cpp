#include <iostream>

using namespace std;

int main()
{
    int pass = 0;

    char buff[8];
    char tempbuff[8];

    cout << (void*)buff << endl;
    cout << (void*)tempbuff << endl;
    cout << &pass << endl;

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

    return 0;
}

