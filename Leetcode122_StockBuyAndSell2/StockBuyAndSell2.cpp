#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int valley = prices[0];
        int peak = prices[0];
        int max_profit = 0;
        int length = prices.size();
        int i = 0;
        while (i < length - 1)
        {
            while (i < length - 1 && prices[i] >= prices[i + 1]) //«Ûµ√≤®π»÷µ
                ++i;
            valley = prices[i];
            while (i < length - 1 && prices[i] <= prices[i + 1])
                ++i;
            peak = prices[i];
            max_profit += (peak - valley);
        }
        return max_profit;
    }
protected:
private:
};

void test1()
{
    cout << "test1 is running......" << endl;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    Solution solution;
    int max_profit = solution.maxProfit(prices);
    cout << "max profit is: " << max_profit << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    vector<int> prices = { 1, 2, 3, 4, 5};
    Solution solution;
    int max_profit = solution.maxProfit(prices);
    cout << "max profit is: " << max_profit << endl;
}

void test3()
{
    cout << "test3 is running......" << endl;
    vector<int> prices = { 7, 6, 4, 3, 1};
    Solution solution;
    int max_profit = solution.maxProfit(prices);
    cout << "max profit is: " << max_profit << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    getchar();
    return 0;
}