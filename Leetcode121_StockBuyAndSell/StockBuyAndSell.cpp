#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices)
    {
        int min_price = INT_MAX;
        int max_profit = 0;
        int length = prices.size();
        for (int i = 0; i < length; ++i)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            } 
            else if((prices[i] - min_price) > max_profit)
            {
                max_profit = prices[i] - min_price;
            }
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
    int maxProfit = solution.maxProfit(prices);
    cout << "maxProfit is: "<< maxProfit << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    vector<int> prices = { 7, 6, 4, 3, 1 };
    Solution solution;
    int maxProfit = solution.maxProfit(prices);
    cout << "maxProfit is: " << maxProfit << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}