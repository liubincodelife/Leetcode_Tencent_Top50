#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    //先排序，然后返回中间位置的数即为众数
    int majorityElement1(vector<int> nums)
    {
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }

    int majorityElement2(vector<int> nums)
    {
        int count = 1;
        int majorNum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (majorNum == nums[i])
            {
                ++count;
            }
            else
            {
                --count;
                if (count == 0)
                {
                    majorNum = nums[i+1];
                }
            }
        }

        return majorNum;
    }
protected:
private:
};

void test1()
{
    cout << "test1 is running......" << endl;
    vector<int> nums = { 3, 2, 3 };
    Solution solution;
    int majorityNum = solution.majorityElement1(nums);
    cout << "the majority num1 is: " << majorityNum << endl;

    majorityNum = solution.majorityElement2(nums);
    cout << "the majority num2 is: " << majorityNum << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    vector<int> nums = { 2, 2, 1, 1, 1, 2, 2 };
    Solution solution;
    int majorityNum = solution.majorityElement1(nums);
    cout << "the majority num1 is: " << majorityNum << endl;

    majorityNum = solution.majorityElement2(nums);
    cout << "the majority num2 is: " << majorityNum << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
        
    getchar();
    return 0;
}