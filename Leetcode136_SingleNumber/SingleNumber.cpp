#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        if (nums.size() == 0)
            throw new exception("invalid parameter");
        //遍历一遍数组，挨个将每个元素进行异或操作，最终得到的数字就是只出现一次的数字
        //0和数字异或得到数字本身，两个相同的数字进行异或为0
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            result ^= nums[i];
        }
        return result;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}