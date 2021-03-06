// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream>
using namespace std;

class Kwadrat
{
public:
    // konstruktor
    Kwadrat(int a)
    {
        this->a = a;
        cout << "Tworze kwadrat o boku " << a << endl;
    }

    // destruktor - metoda wywoływana kiedy obiekt jest usuwany
    // destruktora używamy do zwalniania zasobów których wcześniej używaliśmy, np.
    // - zwalniania zaalokowanej pamięci
    // - zamykania utwartych plików
    ~Kwadrat()
    {
        cout << "Usuwam kwadrat o boku " << a << endl;
    }

private:
    int a;
};

// W C++ obowiązkiem programisty jest zarządzanie pamięcią.
// Upraszczając mamy dwie metody tworzenia obiektów w pamięci:
// 1) na stosie ('stack')
// 2) na stercie ('heap')
int main()
{
    // tworzenie obiektu na stosie
    // obiekt żyje do czasu wyjścia z zakresu - do napotkania klamry zamykającej '}'
    Kwadrat k1(100);

    // tworzenie obiektu na stercie
    // obiekty żyje do czasu wywołania operatora 'delete'
    Kwadrat *k2 = new Kwadrat(5555);
    delete k2;

    cout << "Wyjscie z programu" << endl;
    // uruchom program i zobacz co zostanie wypisane na ekranie

    return 0;
}
