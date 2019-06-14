#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        if (nums.size() == 0)
            throw new exception("invalid parameter");
        //����һ�����飬������ÿ��Ԫ�ؽ��������������յõ������־���ֻ����һ�ε�����
        //0���������õ����ֱ���������ͬ�����ֽ������Ϊ0
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            result ^= nums[i];
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