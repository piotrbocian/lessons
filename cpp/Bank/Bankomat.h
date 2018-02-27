#pragma once

#include <string>
using namespace std;
class Bankomat
{
public:
	Bankomat();
	~Bankomat();

	void wczytajKarte(string karta);
	void wyplac(float pln);
	void wysunKarte();

private:
	bool karta_rozpoznana = false;
};

