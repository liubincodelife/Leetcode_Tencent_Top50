#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& num)
    {
        vector<vector<int>> result;
        BackPack(num, result, 0);
        return result;
    }

    void swap(int& num1, int& num2)
    {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    void BackPack(vector<int>& num, vector<vector <int>>& result, int first)
    {
        if (first == num.size())
            result.push_back(num);
        for (int i = first; i < num.size(); ++i)
        {
            swap(num[first], num[i]);
            BackPack(num, result, first + 1);
            //得到结果后还原继续下一次搜索
            swap(num[first], num[i]);
        }
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}