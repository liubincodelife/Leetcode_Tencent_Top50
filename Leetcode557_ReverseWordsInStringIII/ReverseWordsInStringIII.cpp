#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.length() == 0)
            return "";
        int start = 0;
        for (int i = 0; i <= s.length(); ++i)  //此处要取等号
        {
            if (s[i] == ' ' || s[i] == '\0')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

    void reverse(string& str, int start, int end)
    {
        while (start < end)
        {
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
            ++start;
            --end;
        }
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}