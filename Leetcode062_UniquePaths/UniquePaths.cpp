#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //¶¯Ì¬¹æ»®
    int uniquePaths(int m, int n)
    {
        if (m <= 0 && n <= 0)
            return -1;

        vector<vector<int>> paths(n, vector<int>(m));
        for (int i = 0; i < m; ++i)
        {
            paths[0][i] = 1;
        }

        for (int i = 0; i < n; ++i)
        {
            paths[i][0] = 1;
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }

        return paths[n - 1][m - 1];
    }
protected:
private:
};

void test1()
{
    cout << "test1 is running......" << endl;
    int m = 3;
    int n = 2;
    Solution solution;
    int count = solution.uniquePaths(m, n);
    cout << "the path count is: " << count << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    int m = 7;
    int n = 3;
    Solution solution;
    int count = solution.uniquePaths(m, n);
    cout << "the path count is: " << count << endl;
}


int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}