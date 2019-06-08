#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int length = s.size();
        if (length == 0)
            return;
        int left = 0;
        int right = length - 1;
        while (left < right)
        {
            char tmpChar = s[left];
            s[left] = s[right];
            s[right] = tmpChar;
            ++left;
            --right;
        }
    }
protected:
private:
};

void printString(vector<char> strVec)
{
    for (int i = 0; i < strVec.size(); ++i)
    {
        cout << strVec[i] << " ";
    }
    cout << endl;
}

void test(vector<char>& strVec)
{
    Solution solution;
    cout << "the origin string is: " << endl;
    printString(strVec);
    solution.reverseString(strVec);

    cout << "the reverse string is: " << endl;
    printString(strVec);
}

void test1()
{
    vector<char> strVec = { 'h', 'e', 'l', 'l', 'o' };
    test(strVec);
}

void test2()
{
    vector<char> strVec = { 'a', '.' };
    test(strVec);
}

void test3()
{
    vector<char> strVec = { 'H', 'a', 'n', 'n', 'a', 'h' };
    test(strVec);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    getchar();
    return 0;
}