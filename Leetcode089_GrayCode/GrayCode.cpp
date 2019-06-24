#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //ʹ�ö�̬�滮�ķ���
    vector<int> grayCode(int n)
    {
        vector<int> result;
        result.push_back(0);  //���ױ���ĵ�һ��Ԫ��Ϊ0
        for (int i = 0; i < n; ++i)
        {
            int addBits = 1 << i;
            for (int j = result.size()-1; j >= 0; --j)
            {
                int tmp = result[j] + addBits;
                result.push_back(tmp);
            }
        }
        return result;
    }
protected:
private:
};

void test()
{
    int n = 2;
    Solution solution;
    vector<int> retCode = solution.grayCode(n);
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}