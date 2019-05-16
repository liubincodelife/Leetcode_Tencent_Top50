#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsDuplicate1(vector<int> nums)
    {
        //先排序再遍历查找
        sort(nums.begin(), nums.end(), less<int>());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }

    bool containsDuplicate2(vector<int> nums)
    {
        //使用set保存数组，重复的数据会被剔除
        set<int> numSet(nums.begin(), nums.end());
        if (numSet.size() < nums.size())
        {
            return true;
        }
        return false;
    }

    bool containsDuplicate3(vector<int> nums)
    {
        map<int, int> mymap;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mymap.count(nums[i]))
            {
                return true;
            }
            else
            {
                mymap.insert(pair<int, int>(nums[i], 1));
            }
        }
        return false;
    }
protected:
private:
};

void test1()
{
    cout << "test1 is running......" << endl;
    vector<int> nums = { 1, 2, 3, 1 };
    Solution solution;
    bool retValue = solution.containsDuplicate1(nums);

    if (retValue)
    {
        cout << "nums contains duplicate num......" << endl;
    }
    else
    {
        cout << "nums don't contains duplicate num......" << endl;
    }
}

void test2()
{
    cout << "test2 is running......" << endl;
    vector<int> nums = { 1, 2, 3, 4 };
    Solution solution;
    bool retValue = solution.containsDuplicate2(nums);

    if (retValue)
    {
        cout << "nums contains duplicate num......" << endl;
    }
    else
    {
        cout << "nums don't contains duplicate num......" << endl;
    }
}

void test3()
{
    cout << "test3 is running......" << endl;
    vector<int> nums = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    Solution solution;
    bool retValue = solution.containsDuplicate3(nums);

    if (retValue)
    {
        cout << "nums contains duplicate num......" << endl;
    }
    else
    {
        cout << "nums don't contains duplicate num......" << endl;
    }
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();

    getchar();
    return 0;
}