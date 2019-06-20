#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        //满足2的幂的数n的二进制只有一位为1，否则就不是2的幂；n-1则变为后面的位都为1，原来为1的位变成0
        //所以只需要计算n&(n-1)，判断其结果是否等于0即可
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
            return true;
        return false;
    }
    //正常的做法
    bool isPowerOfTwo2(int n)
    {
        if (n <= 0)
            return false;
        while (n%2 == 0 && n > 0)
        {
            n /= 2;
        }
        if (n == 1)
            return true;
        return false;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}