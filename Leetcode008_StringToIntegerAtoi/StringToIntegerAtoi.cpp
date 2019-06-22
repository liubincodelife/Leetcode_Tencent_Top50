#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int index = 0, flag = 1;
        int length = str.length();
        int result = 0;
        while (index < length && str[index] == ' ')
        {
            ++index;
        }
        //字符串所有字符为空字符
        if (index == length)
            return 0;
        //判断第一个非空字符
        else if (str[index] == '-')
            flag = -1;
        else if (str[index] >= '0' && str[index] <= '9')
            result = str[index] - '0';
        else if (str[index] != '+')
            return 0;
        while (++index < length && str[index] >= '0' && str[index] <= '9')
        {
            int tmp = (str[index] - '0') * flag;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && tmp > 7))//注意加括号
                return INT_MAX;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && tmp < -8))//注意加括号
                return INT_MIN;
            result = result * 10 + tmp;
        }

        return result;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}