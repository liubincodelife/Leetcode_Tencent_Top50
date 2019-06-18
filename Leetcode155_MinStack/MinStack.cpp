#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
public:
    MinStack()
    {

    }

    void push(int x) //��Ԫ��x����ջ��
    {
        vecStack.push_back(x);
        if (minStack.size() == 0 || x <= minStack.back())
            minStack.push_back(x);
    }

    void pop() //ɾ��ջ��Ԫ��
    {
        if (vecStack.size() > 0)
        {
            int topValue = vecStack.back();
            if (topValue == minStack.back())
                minStack.pop_back();
            vecStack.pop_back();
        } 
    }

    int top() //��ȡջ��Ԫ��
    {
        int retValue = -1;
        if(vecStack.size() > 0)
            retValue = vecStack.back();
        return retValue;
    }

    int getMin()  //����ջ�е���СԪ��
    {
        if (minStack.size() == 0)
            return -1;

        return minStack.back();
    }
protected:
private:
    vector<int> vecStack;
    vector<int> minStack;  //������Ŀ��˼Ҫ���ȡ��Сֵ��ʱ�临�Ӷ�Ϊ��������������Ҫһ������ջ
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}