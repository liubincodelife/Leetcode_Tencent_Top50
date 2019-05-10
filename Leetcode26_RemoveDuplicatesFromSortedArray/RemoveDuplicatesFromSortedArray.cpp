#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int length = nums.size();
        int i = 0;
        for (int j = 1; j < length; j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return (i + 1);
    }
protected:
private:
};

void test1()
{
    vector<int> nums = { 1, 1, 2 };
    Solution solution;
    int length = solution.removeDuplicates(nums);
    cout << "\ntest case1 after remove duplicates is: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
}

void test2()
{
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    Solution solution;
    int length = solution.removeDuplicates(nums);
    cout << "\ntest case2 after remove duplicates is: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}