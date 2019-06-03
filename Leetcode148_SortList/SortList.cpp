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
        //1.快慢指针找中间节点
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
        //2.递归调用mergeSort对链表进行划分
        ListNode* pLeftNode = mergeSort(pNode);
        ListNode* pRightNode = mergeSort(pSlowNode);
        //3.对划分区域后的排序结果进行合并
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