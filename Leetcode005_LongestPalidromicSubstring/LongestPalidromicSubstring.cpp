#include <iostream>
#include <string>

using namespace std;

class Solution_1
{
public:
    string longestPalidrome(string s)
    {
        string result;
        string tmpStr;
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = i; j <s.length(); ++j)
            {
                tmpStr = tmpStr + s[j];
                string tmp = tmpStr;
                reverse(tmp.begin(), tmp.end());
                if (tmpStr == tmp)
                {
                    result = result.length() > tmpStr.length() ? result : tmpStr;
                }
            }
        }

        return result;
    }
protected:
private:
};

void test1()
{
    string testStr = "babad";
    Solution_1 solution1;
    string result = solution1.longestPalidrome(testStr);
    cout << "the longest palidrome string is: " << result << endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}