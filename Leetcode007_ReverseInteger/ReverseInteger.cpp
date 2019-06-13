#include <iostream>

using namespace std;

class Solution
{
public:
    //�˷���Ϊ��֪��������жϵ���ѧ���������
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            int popNum = x % 10;  //�����λ����ȡ��
            x /= 10;              //ȡ�����λ���ֺ����x��ֵ
            //�ж�result�Ƿ��Ͻ����
            if (result > INT_MAX / 10 || ( result == INT_MAX / 10 && popNum > 7 ))
                return 0;
            //�ж�result�Ƿ��½����
            if (result < INT_MIN || (result == INT_MIN / 10 && popNum < -8))
                return 0;
            result = result * 10 + popNum;
        }

        return result;
    }

    //������δ֪���������������ֱ���ڳ����к����ֵ���бȽ����ж������Ƿ����
    int reverse2(int x)
    {
        unsigned int max_value = 1 << 31;
        long long result = 0, xx = (long long)x;
        //��ȡx�ľ���ֵ
        xx = abs(xx);
        while (xx)
        {
            result = result * 10 + xx % 10;
            xx = xx / 10;
        }
        if (x < 0)  //��x<0ʱ���ж��Ƿ����
        {
            if (result > max_value)
                return 0;
            else
                return (int)(-result);  //�ǵ�ǿת��
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