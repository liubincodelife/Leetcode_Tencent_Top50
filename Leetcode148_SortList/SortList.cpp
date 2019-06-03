#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* pNode)
    {
        if (!pNode || !pNode->next)
            return pNode;
        //1.����ָ�����м�ڵ�
        ListNode* pFastNode = pNode;
        ListNode* pSlowNode = pNode;
        ListNode* pBreakNode = pNode;
        while (pFastNode && pFastNode->next)
        {
            pFastNode = pFastNode->next->next;
            pBreakNode = pSlowNode;
            pSlowNode = pSlowNode->next;
        }
        pBreakNode->next = nullptr;
        //2.�ݹ����mergeSort��������л���
        ListNode* pLeftNode = mergeSort(pNode);
        ListNode* pRightNode = mergeSort(pSlowNode);
        //3.�Ի������������������кϲ�
        return merge(pLeftNode, pRightNode);
    }

    ListNode* merge(ListNode* pLeft, ListNode* pRight)
    {
        if (pLeft == nullptr)
            return pRight;
        if (pRight == nullptr)
            return pLeft;
        if (pLeft->val < pRight->val)
        {
            pLeft->next = merge(pLeft->next, pRight);
            return pLeft;
        } 
        else
        {
            pRight->next = merge(pLeft, pRight->next);
            return pRight;
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