#include <iostream> 
#include <stack>
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
    string line = "()(){[]}";

    cout << ((isBalanced(line)) ? "YES\n" : "NO\n");

    return 0;
}