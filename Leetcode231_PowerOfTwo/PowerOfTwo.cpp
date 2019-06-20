#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        //����2���ݵ���n�Ķ�����ֻ��һλΪ1������Ͳ���2���ݣ�n-1���Ϊ�����λ��Ϊ1��ԭ��Ϊ1��λ���0
        //����ֻ��Ҫ����n&(n-1)���ж������Ƿ����0����
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
            return true;
        return false;
    }
    //����������
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