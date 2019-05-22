#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        if (n <= 0)
            return{};
        int rows = n;
        int cols = n;
        int start = 0;
        int num = 0;
        vector<vector<int>> matrix(n, vector<int>(n));
        while (rows > start * 2 && cols > start * 2)
        {
            int endX = cols - 1 - start;
            int endY = rows - 1 - start;

            for (int i = start; i <= endX; ++i)
            {
                matrix[start][i] = ++num;
            }

            for (int i = start + 1; i <= endY; ++i)
            {
                matrix[i][endX] = ++num;
            }

            if (start < endX && start < endY)
            {
                for (int i = endX - 1; i >= start; --i)
                {
                    matrix[endY][i] = ++num;
                }
            }

            if (start < endX && start < endY)
            {
                for (int i = endY - 1; i >= start + 1; --i)
                {
                    matrix[i][start] = ++num;
                }
            }

            ++start;
        }

        return matrix;

    }
};

void test1()
{
    int n = 3;
    Solution solution;
    vector<vector<int>> matrix = solution.generateMatrix(n);

    for (auto it1 = matrix.begin(); it1 != matrix.end(); ++it1)
    {
        vector<int> subVector = *it1;
        for (auto it2 = subVector.begin(); it2 != subVector.end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}