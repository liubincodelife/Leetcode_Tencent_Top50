#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //动态规划
    int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<int> steps(n + 1);
        steps[1] = 1;
        steps[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            steps[i] = steps[i - 1] + steps[i - 2];
        }

        return steps[n];
    }

    //斐波那契递推公式法
    int climbStairs2(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int fn_1 = 2;
        int fn_2 = 1;
        int fn = 0;
        for (int i = 3; i <= n; ++i)
        {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}