#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int length = nums.size();
        int product = 0;
        vector<int> retVector(length, 1);
        //�ȴ�ͷ��β����һ�Σ�����˻�
        int temp = 1;
        for (int i = 0; i < length; ++i)
        {
            retVector[i] *= temp;
            temp *= nums[i];
        }

        //�ٴ�β��ͷ����һ�Σ�����ʣ�����ֳ˻�
        temp = 1;
        for (int i = length - 1; i >= 0; --i)
        {
            retVector[i] *= temp;
            temp *= nums[i];
        }

        return retVector;
    }
protected:
private:
};

void test()
{
    vector<int> nums = { 1, 2, 3, 4 };
    Solution solution;
    vector<int> product = solution.productExceptSelf(nums);
    for (auto it = product.begin(); it != product.end(); ++it)
    {
        cout << *it << " ";
    }
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}