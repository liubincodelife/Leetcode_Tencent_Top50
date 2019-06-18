#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        //字符串为空，直接返回true
        if (s.length() == 0)
            return true;
        vector<char> operateStr;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                operateStr.push_back(s[i]);
            else
            {
                if (operateStr.size() == 0)
                    return false;
                char tmpChar = operateStr.back();
                if (s[i] == ')' && tmpChar == '(')
                    operateStr.pop_back();
                else if (s[i] == '}' && tmpChar == '{')
                    operateStr.pop_back();
                else if (s[i] == ']' && tmpChar == '[')
                    operateStr.pop_back();
                else
                    return false;
            }
        }
        return true;
    }
protected:
private:
};

void test(string s)
{
    Solution solution;
    bool result = solution.isValid(s);
    if (result)
        cout << "the string has valid parentheses" << endl;
    else
        cout << "the string don not has valid parentheses" << endl;
}

void test1()
{
    string s = "{[]}";
    test(s);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}