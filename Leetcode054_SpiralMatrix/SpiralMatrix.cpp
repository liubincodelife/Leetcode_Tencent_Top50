#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> spiralMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.size() <= 0)
            return{};
        int start = 0;  //每层循环的起始点坐标为(start, start)
        vector<int> retVector;
        int columns = matrix[0].size();
        int rows = matrix.size();
        while (rows > start * 2 && columns > start * 2)
        {
            int endX = columns - 1 - start;
            int endY = rows - 1 - start;
            //从左到右取数字，必须经过的阶段
            for (int i = start; i <= endX; ++i)
            {
                retVector.push_back(matrix[start][i]);
            }
            //从上到下取数字
            for (int i = start + 1; i <= endY; ++i)
            {
                retVector.push_back(matrix[i][endX]);
            }

            //从右到左取数字
            if (start < endX && start < endY)
            {
                for (int i = endX - 1; i >= start; --i)
                {
                    retVector.push_back(matrix[endY][i]);
                }
            }

            //从下到上取数字
            if (start < endX && start < endY)
            {
                for (int i = endY - 1; i >= start + 1; --i)
                {
                    retVector.push_back(matrix[i][start]);
                }
            }
            

            ++start;
        }

        return retVector;
    }
protected:
private:
};

//若不加条件限制，会多打印从右往左的数字
void test1()
{
    cout << "test1 is running......" << endl;
    vector<vector<int>> matrix = { 
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (int i = 0; i < retVector.size(); ++i)
    {
        cout << retVector[i] << " ";
    }
    cout << endl;
}

//若不加条件限制，会触发从下到上
void test2()
{
    cout << "test2 is running......" << endl;
    vector<vector<int>> matrix = {
        { 7 },
        { 9 },
        { 6 }
    };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (int i = 0; i < retVector.size(); ++i)
    {
        cout << retVector[i] << " ";
    }
    cout << endl;
}

void test3()
{
    cout << "test3 is running......" << endl;
    vector<vector<int>> matrix = {
        { 7 }
    };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (int i = 0; i < retVector.size(); ++i)
    {
        cout << retVector[i] << " ";
    }
    cout << endl;
}

void test4()
{
    cout << "test4 is running......" << endl;
    vector<vector<int>> matrix = {
        { 7, 8, 9}
    };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (int i = 0; i < retVector.size(); ++i)
    {
        cout << retVector[i] << " ";
    }
    cout << endl;
}

void test5()
{
    cout << "test5 is running......" << endl;
    vector<vector<int>> matrix = {
        { 1, 2},
        { 5, 6},
        { 9, 10}
    };
    Solution solution;
    vector<int> retVector = solution.spiralMatrix(matrix);
    for (int i = 0; i < retVector.size(); ++i)
    {
        cout << retVector[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    getchar();
    return 0;
}