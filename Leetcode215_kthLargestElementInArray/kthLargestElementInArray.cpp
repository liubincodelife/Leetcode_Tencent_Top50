#include <iostream>
#include <vector>
#include <queue>
#include<functional>  //ʹ��greater��Ҫ������ͷ�ļ�

using namespace std;

class Solution
{
public:
    //ʹ�����ȼ����й����С����������ǰk������֣�Ȼ�󷵻ضѶ���Ϊ��k�������
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

    //ʹ�ÿ���˼��
protected:
private:
};

int main(int argc, char** argv)
{

    getchar();
    return 0;
}