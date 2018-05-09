// Copyright 2018 Piotr Bocian
// Opracowanie Piotr Bocian

#include <iostream> 
#include <stack>
#include <cassert>
using namespace std;

bool isLeft(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool isMatching(char left, char right)
{
    return (
        (left == '(' && right == ')') ||
        (left == '{' && right == '}') ||
        (left == '[' && right == ']')
        );
}

bool isBalanced(string line)
{
    std::stack<char> st;

    for (auto c : line)
    {
        if (isLeft(c))
        {
            st.push(c);
        }
        else
        {
            if (!st.empty() && isMatching(st.top(), c))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

int nawiasy()
{
    assert(isBalanced("()") == true);
    assert(isBalanced("{}") == true);
    assert(isBalanced("({})") == true);
    assert(isBalanced("[]") == true);
    assert(isBalanced("[][]") == true);
    assert(isBalanced("{[()]}") == true);

    assert(isBalanced("(") == false);
    assert(isBalanced("{") == false);
    assert(isBalanced("[") == false);
    assert(isBalanced("]") == false);
    assert(isBalanced("}") == false);
    assert(isBalanced(")") == false);
    assert(isBalanced("(]") == false);
    assert(isBalanced("([)]") == false);
    assert(isBalanced("((())") == false);

    assert(isBalanced("()") == true);
    assert(isBalanced("(") == false);
    assert(isBalanced("[()]") == true);
    assert(isBalanced("({}])") == false);
    assert(isBalanced("") == true);

    string line = "()(){[]}";
    cout << ((isBalanced(line)) ? "YES\n" : "NO\n");

    return 0;
}