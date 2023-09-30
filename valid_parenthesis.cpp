#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> sp;
        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                sp.push(ch);
            }
            else
            {
                if (sp.empty())
                {
                    return false;
                }
                if (ch == ')' && sp.top() == '(')
                {
                    sp.pop();
                }
                else if (ch == '}' && sp.top() == '{')
                {
                    sp.pop();
                }
                else if (ch == ']' && sp.top() == '[')
                {
                    sp.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return sp.empty();
    }
};

int main()
{
    string str;
    cout << "Enter a string with '(,),{,},[,]': ";
    getline(cin, str);
    Solution s1;
    int result = s1.isValid(str);
    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}