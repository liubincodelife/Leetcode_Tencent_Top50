#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int length = nums.size();
        if (length == 0)  //注意要判断数组为空的情况
            return 0;
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

//测试包含重复数据的数组1
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

//测试包含重复数据的数组2
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

//测试数组为空的情况
void test3()
{
    vector<int> nums;
    Solution solution;
    int length = solution.removeDuplicates(nums);
    if (length == 0)
        cout << "\nthe array is empty!!" << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    getchar();
    return 0;
}