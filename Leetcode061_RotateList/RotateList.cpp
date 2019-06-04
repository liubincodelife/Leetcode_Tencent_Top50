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
        if (head == nullptr || k < 0)  //若链表为空，直接返回
            return nullptr;
        if (head->next == nullptr)  //若链表只有一个节点，直接返回
            return head;
        //1.找到原链表中的尾节点并将尾节点指向原头节点，方便向右循环移动
        ListNode* pNode = head;
        int length = 1;
        while(pNode->next != nullptr)
        {
            ++length;
            pNode = pNode->next;
        }
        pNode->next = head;
        //2.计算新的尾节点位置，并将链表断开
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