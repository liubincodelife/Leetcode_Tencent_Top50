#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
public:
    MinStack()
    {

    }

    void push(int x) //将元素x推入栈中
    {
        vecStack.push_back(x);
        if (minStack.size() == 0 || x <= minStack.back())
            minStack.push_back(x);
    }

    void pop() //删除栈顶元素
    {
        if (vecStack.size() > 0)
        {
            int topValue = vecStack.back();
            if (topValue == minStack.back())
                minStack.pop_back();
            vecStack.pop_back();
        } 
    }

    int top() //获取栈顶元素
    {
        int retValue = -1;
        if(vecStack.size() > 0)
            retValue = vecStack.back();
        return retValue;
    }

    int getMin()  //返回栈中的最小元素
    {
        if (minStack.size() == 0)
            return -1;

        return minStack.back();
    }
protected:
private:
    vector<int> vecStack;
    vector<int> minStack;  //由于题目意思要求获取最小值的时间复杂度为常数级，所以需要一个辅助栈
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}