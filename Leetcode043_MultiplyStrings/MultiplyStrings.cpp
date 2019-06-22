#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int length1 = num1.length(), length2 = num2.length();
        int index = 0;
        vector<int> resultVec(length1 + length2, 0);
        for (int i = length1 - 1; i >= 0; --i)
        {
            index = length1 - 1 - i;
            for (int j = length2 - 1; j >= 0; --j)
            {
                int tmpNum1 = num1[i] - '0';
                int tmpNum2 = num2[j] - '0';
                int result = tmpNum1 * tmpNum2 + resultVec[index];
                if (result >= 10)
                    resultVec[index + 1] += result / 10;
                resultVec[index] = result % 10;
                ++index;
            }
        }

        string resultStr = "";
        int realLength = length1 + length2 - 1;
        //去掉最高位的0，计算结果的真实位数
        while (realLength >= 0 && resultVec[realLength] == 0)
            realLength--;
        for (int i = realLength; i >= 0; --i)  //由于中间可能有0，所以要从后向前遍历
        {
            resultStr = resultStr + char(resultVec[i] + '0');
        }
        return resultStr.empty() ? "0" : resultStr;
    }

    //此方法不适用于大数相乘问题，会导致溢出
    string multiply2(string num1, string num2)
    {
        int length1 = num1.length();
        int length2 = num2.length();
        int index = 0;
        int num11 = 0;
        int num22 = 0;
        while (index < length1)
        {
            int tmp = num1[index] - '0';
            if (tmp == 0)
                num11 = 0;
            else
                num11 = num11 * 10 + tmp;
            ++index;
        }
        index = 0;
        while (index < length2)
        {
            int tmp = num2[index] - '0';
            if (tmp == 0)
                num22 = 0;
            else
                num22 = num22 * 10 + tmp;
            ++index;
        }
        long long result = num11 * num22;  //改成long long类型还是会溢出
        string resultStr;
        //将result转换成字符串
        while (result > 0)
        {
            int tmp = result % 10;
            result /= 10;
            char tmpChar = tmp + '0';
            resultStr.insert(resultStr.begin(), 1, tmpChar);
        }
        return resultStr;
    }
protected:
private:
};

void test(string num1, string num2)
{
    Solution solution;
    string returnStr = solution.multiply(num1, num2);
}

void test1()
{
    string num1 = "2";
    string num2 = "3";
    test(num1, num2);
}

void test2()
{
    string num1 = "123";
    string num2 = "456";
    test(num1, num2);
}

int main(int argc, char** argv)
{
    test2();
    getchar();
    return 0;
}