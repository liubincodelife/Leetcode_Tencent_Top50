#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//遍历数组，时间复杂度为O(n)
class Solution
{
public:
    int maxSubArray(vector<int> nums)
    {
        int max_sofar = nums[0];
        int max_end = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            max_end = max(nums[i], max_end + nums[i]);
            max_sofar = max(max_sofar, max_end);
        }

        return max_sofar;
    }
protected:
private:
};

void test()
{
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    Solution solution;
    int maxSum = solution.maxSubArray(nums);
    cout << "the max sum is:" << maxSum << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}