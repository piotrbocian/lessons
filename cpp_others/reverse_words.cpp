// Example program
#include <iostream>
#include <string>
#include <algorithm>

void reverse(std::string &s, int b, int e)
{
    //std::cout << "reverse " << s << b << e << std::endl;
    std::string new_s = "";
    std::reverse(std::begin(s)+b, std::begin(s)+e);
}

int main()
{
    std::string tekst = "Ala ma kota i psa";
    reverse(tekst, 0, tekst.length());
    
    int begin = 0;
    int end = 0;
    
    for (int i = 0; i<tekst.length(); )
    {
        
        for (; i<tekst.length(); i++)
        {
            if (std::isalpha(tekst[i]))
            {
                begin = i;
                break;
            }
        }
        
        for (; i<=tekst.length(); i++)
        {
            if (!std::isalpha(tekst[i]))
            {
                end = i;
                break;
            }
        }

        
        reverse(tekst, begin, end);
    }
    
    
    std::cout << tekst;
}
