#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    vector<vector<int>> subsets(vector<int> nums)
    {
        vector<vector<int>> retSubSets;
        int length = nums.size();
        if (length == 0)
        {
            return retSubSets;
        }
        
        vector<int> subset;
        for (int count = 0; count <= length; ++count)
        {
            searchNums(nums, retSubSets, subset, count, 0);
            subset.clear();
        }

        return retSubSets;
    }
protected:
private:
    void searchNums(vector<int>& nums, vector<vector<int>>& retSubSets, vector<int>& subSet, int count, int index)
    {
        if (count == 0)
        {
            retSubSets.push_back(subSet);
            return;
        }

        for (;index < nums.size(); ++index)
        {
            --count;
            subSet.push_back(nums[index]);
            searchNums(nums, retSubSets, subSet, count, index + 1);
            subSet.pop_back();
            ++count;
        }
    }
};

//回溯法的通用解法
class SolutionCommon
{
public:
    vector<vector<int>> subsets(vector<int> nums)
    {
        vector<vector<int>> retSubsets;
        vector<int> subset;
        if (nums.size() == 0)
        {
            return retSubsets;
        }
        sort(nums.begin(), nums.end());
        backTrack(retSubsets, subset, nums, 0);
        return retSubsets;
    }
protected:
private:
    void backTrack(vector<vector<int>>& retSubsets, vector<int>& subset, vector<int>& nums, int start)
    {
        retSubsets.push_back(subset);
        for (int i = start; i < nums.size(); ++i)
        {
            subset.push_back(nums[i]);
            backTrack(retSubsets, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

void test1()
{
    cout << "test1 is running......" << endl;
    vector<int> nums = { 1, 2, 3, 4 };
    Solution solution;
    vector<vector<int>> retSubsets = solution.subsets(nums);
    for (auto it1 = retSubsets.begin(); it1 != retSubsets.end(); ++it1)
    {
        vector<int> tempSet = *it1;
        cout << "[ ";
        for (auto it2 = tempSet.begin(); it2 != tempSet.end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout <<"]"<< endl;
    }
}

void test2()
{
    cout << "test2 is running......" << endl;
    vector<int> nums = { 1, 2, 3, 4 };
    SolutionCommon solution;
    vector<vector<int>> retSubsets = solution.subsets(nums);
    for (auto it1 = retSubsets.begin(); it1 != retSubsets.end(); ++it1)
    {
        vector<int> tempSet = *it1;
        cout << "[ ";
        for (auto it2 = tempSet.begin(); it2 != tempSet.end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << "]" << endl;
    }
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}
