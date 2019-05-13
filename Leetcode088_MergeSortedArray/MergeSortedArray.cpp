#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p2 = n - 1;
        int p1 = m - 1;
        int p = m + n - 1;
        while (p1 >= 0 && p2 >= 0) //当nums1和nums2都不为空时，从后向前插入
        {
            if (nums1[p1] > nums2[p2])
            {
                nums1[p] = nums1[p1];
                p1--;
            } 
            else
            {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        while (p2 >= 0)  //当nums1为空时，将nums2直接插入nums1数组
        {
            nums1[p--] = nums2[p2--];
        }
    }
protected:
private:
};

void test1()
{
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2, 5, 6 };
    Solution solution;
    cout << "\ntest1 running......" << endl;
    int len1 = nums1.size() - nums2.size();
    int len2 = nums2.size();
    solution.merge(nums1, len1, nums2, len2);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
}

void test2()
{
    vector<int> nums1 = { 0 };
    vector<int> nums2 = { 1 };
    Solution solution;
    cout << "\ntest2 running......" << endl;
    int len1 = max((int)(nums1.size() - nums2.size()), 0);
    int len2 = nums2.size();
    solution.merge(nums1, len1, nums2, len2);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}