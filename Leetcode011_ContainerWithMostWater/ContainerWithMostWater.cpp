#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        if (height.size() <= 1)
            return 0;
        int maxCapacity = INT_MIN;
        int length = height.size();
        int i = 0, j = length - 1;
        int width = length - 1;
        while (width > 0)
        {
            int tempCapacity = width * min(height[i], height[j]);
            if (tempCapacity > maxCapacity)
            {
                maxCapacity = tempCapacity;
            }

            if (height[i] <= height[j])
            {
                ++i;
            }
            else
            {
                --j;
            }
            --width;
        }
        return maxCapacity;
    }
protected:
private:
};

void test()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    int retValue = solution.maxArea(height);
    cout << "the max capacity is: " << retValue << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}