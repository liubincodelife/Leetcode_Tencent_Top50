#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        int sumSrc = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < length - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = length - 1;
            while (left < right)
            {
                int curSum = nums[i] + nums[left] + nums[right];
                if (curSum == target)
                {
                    return target;
                }
                if (abs(target - sumSrc) > abs(target - curSum))
                {
                    sumSrc = curSum;
                }
                if (curSum > target)
                {
                    --right;
                }
                else if (curSum < target)
                {
                    ++left;
                }
            }
        }
        return sumSrc;
    }
protected:
private:
};

void test()
{
    vector<int> nums = { -1, 2, 1, -4 };
    int target = 1;

    Solution solution;
    int matchSum = solution.threeSumClosest(nums, target);
    cout << "the closest sum is: " << matchSum  << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}