#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || ((x%10) == 0 && x != 0))
        {
            return false;
        }

        int reverseNum = 0;
        while (x > reverseNum)
        {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }

        return x == reverseNum || x == (reverseNum / 10);
    }

    bool isPalindrome2(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int div = 1;
        while (x / div >= 10)
        {
            div *= 10;
        }

        while (x > 0)
        {
            int high = x / div;
            int low = x % 10;
            if (high != low)
            {
                return false;
            }
            x = (x % div) / 10;  //取剩下的数字继续处理
            div /= 100;
        }

        return true;
    }
protected:
private:
};

//测试回文数字
void test1()
{
    int testNumber = 121;
    Solution solution;
    bool result = solution.isPalindrome(testNumber);
    if (result)
    {
        cout << "the number is a palindromic number......" << endl;
    }
    else
    {
        cout << "the number is not a palindromic number......" << endl;
    }
}

//测试负数
void test2()
{
    int testNumber = -121;
    Solution solution;
    bool result = solution.isPalindrome(testNumber);
    if (result)
    {
        cout << "the number is a palindromic number......" << endl;
    }
    else
    {
        cout << "the number is not a palindromic number......" << endl;
    }
}

//注意：0是回文数
void test3()
{
    int testNumber = 0;  
    Solution solution;
    bool result = solution.isPalindrome(testNumber);
    if (result)
    {
        cout << "the number is a palindromic number......" << endl;
    }
    else
    {
        cout << "the number is not a palindromic number......" << endl;
    }
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    getchar();
    return 0;
}