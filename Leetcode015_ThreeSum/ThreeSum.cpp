#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        if (length < 3 || nums[0] > 0 || nums[length - 1] < 0)
        {
            return{};
        }

        int left = 0;
        int right = length - 1;
        vector<vector<int>> retVector;
        for (int i = 0; i < length - 2; ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = length - 1;
            while (left < right)
            {
                int result = nums[i] + nums[left] + nums[right];
                if (result == 0)
                {
                    retVector.push_back({ nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right &&nums[right] == nums[right - 1])
                        --right;
                    ++left;
                    --right;
                }
                else if (result > 0)
                {
                    --right;
                }
                else
                {
                    ++left;
                }
            }
        }
        return retVector;
    }
protected:
private:
};

void test1()
{
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    //打印二维vector
    for (auto it1 = result.begin(); it1 != result.end(); ++it1)
    {
        vector<int> tmp = *it1;
        for (auto it2 = tmp.begin(); it2 != tmp.end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

void test2()
{
    vector<int> nums = { 0, 0, 0, 0};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    //打印二维vector
    for (auto it1 = result.begin(); it1 != result.end(); ++it1)
    {
        vector<int> tmp = *it1;
        for (auto it2 = tmp.begin(); it2 != tmp.end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}