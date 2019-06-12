#include <iostream>
#include <vector>
#include <queue>
#include<functional>  //使用greater需要包含此头文件

using namespace std;

class Solution
{
public:
    //使用优先级队列构造的小顶堆来保存前k大的数字，然后返回堆顶即为第k大的数字
    int findKthLargest(vector<int> nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap(1, nums[0]);

        for (int i = 0; i < nums.size(); ++i)
        {
            minHeap.push(nums[i]);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
    }

    //使用快排思想
protected:
private:
};

int main(int argc, char** argv)
{

    getchar();
    return 0;
}