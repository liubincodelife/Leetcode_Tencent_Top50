#include <iostream>

using namespace std;

class Solution
{
public:
    //此方法为已知数字溢出判断的数学方法的情况
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            int popNum = x % 10;  //将最低位数字取出
            x /= 10;              //取出最低位数字后更新x的值
            //判断result是否上界溢出
            if (result > INT_MAX / 10 || ( result == INT_MAX / 10 && popNum > 7 ))
                return 0;
            //判断result是否下界溢出
            if (result < INT_MIN || (result == INT_MIN / 10 && popNum < -8))
                return 0;
            result = result * 10 + popNum;
        }

        return result;
    }

    //若事先未知数字溢出条件，则直接在程序中和最大值进行比较来判断数字是否溢出
    int reverse2(int x)
    {
        unsigned int max_value = 1 << 31;
        long long result = 0, xx = (long long)x;
        //先取x的绝对值
        xx = abs(xx);
        while (xx)
        {
            result = result * 10 + xx % 10;
            xx = xx / 10;
        }
        if (x < 0)  //当x<0时，判断是否溢出
        {
            if (result > max_value)
                return 0;
            else
                return (int)(-result);  //记得强转型
        }
        else
        {
            if (result > max_value - 1)
                return 0;
            else
                return (int)result;
        }
        return (int)result;
    }
protected:
private:
};

void test1()
{
    int x = 123;
    Solution solution;
    solution.reverse2(x);

    x = -123;
    solution.reverse(x);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}