#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    //直接通过二分法查找
    int search(vector<int>& nums, int target) 
    {
        int length = nums.size();
        if (length == 0)
            return -1;
        int left = 0;
        int right = length - 1;
        int midIndex = left;
        while (left < right)
        {
            midIndex = (left + right) / 2;
            if (nums[midIndex] == target)
                return midIndex;
            else if (nums[midIndex] >= nums[left])
            {
                if (nums[left] <= target && nums[midIndex] > target)
                {
                    right = midIndex - 1;
                }
                else
                {
                    left = midIndex + 1;
                }
            }
            else if (nums[midIndex] <= nums[right])
            {
                if (nums[midIndex] < target && nums[right] >= target)
                {
                    left = midIndex + 1;
                }
                else
                {
                    right = midIndex - 1;
                }
            }
        }
        int result = nums[left] == target ? left : -1;
        return result;
    }
};

void test1()
{
    cout << "test1 is running......" << endl;
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2};
    Solution solution;
    int retIndex = solution.search(nums, 0);
    cout << "the index of target is: " << retIndex << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2, 3};
    Solution solution;
    int retIndex = solution.search(nums, 3);
    cout << "the index of target is: " << retIndex << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}