#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr || k < 0)  //������Ϊ�գ�ֱ�ӷ���
            return nullptr;
        if (head->next == nullptr)  //������ֻ��һ���ڵ㣬ֱ�ӷ���
            return head;
        //1.�ҵ�ԭ�����е�β�ڵ㲢��β�ڵ�ָ��ԭͷ�ڵ㣬��������ѭ���ƶ�
        ListNode* pNode = head;
        int length = 1;
        while(pNode->next != nullptr)
        {
            ++length;
            pNode = pNode->next;
        }
        pNode->next = head;
        //2.�����µ�β�ڵ�λ�ã���������Ͽ�
        ListNode* pNewTail = head;
        for (int i = 0; i < length - k%length - 1; ++i)
        {
            pNewTail = pNewTail->next;
        }

        ListNode* pNewHead = pNewTail->next;
        pNewTail->next = nullptr;

        return pNewHead;
    }
protected:
private:
};

int main(int argc, char** argv)
{

    getchar();
    return 0;
}