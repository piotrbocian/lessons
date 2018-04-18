#include <cassert>
#include <string>

bool sprawdzPoprawnoscHasla(std::string s)
{
    return true;
}

void sprawdzPoprawnoscHasla_test()
{
    assert(sprawdzPoprawnoscHasla("") == false);
    assert(sprawdzPoprawnoscHasla("tylko_male_litery") == false);
    assert(sprawdzPoprawnoscHasla("male_litery_123") == false);
    assert(sprawdzPoprawnoscHasla("male_litery_1!") == false);
    assert(sprawdzPoprawnoscHasla("DUZE133445!") == false);
    assert(sprawdzPoprawnoscHasla("><?\\12312442") == false);
    assert(sprawdzPoprawnoscHasla("Abc123%") == false);
    assert(sprawdzPoprawnoscHasla("Poprawne1!Poprawne1!1") == false);

    assert(sprawdzPoprawnoscHasla("Poprawne1!") == true);
    assert(sprawdzPoprawnoscHasla("Popraw1&") == true);
    assert(sprawdzPoprawnoscHasla("Poprawne1!Poprawne1!") == true);
}
