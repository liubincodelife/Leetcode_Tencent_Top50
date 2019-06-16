#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            int j = 0;
            for (;j < prefix.size() && j < strs[i].size(); ++j)
            {
                if (prefix[j] != strs[i][j])
                    break;
            }
            prefix = prefix.substr(0, j);
        }

        return prefix;
    }
protected:
private:
};

void test(vector<string>& strs)
{
    Solution solution;
    string prefix = solution.longestCommonPrefix(strs);
    cout << "prefix is: " << prefix.c_str() << endl;
}

void test1()
{
    vector<string> strs = { "flower", "flow", "flight" };
    test(strs);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}