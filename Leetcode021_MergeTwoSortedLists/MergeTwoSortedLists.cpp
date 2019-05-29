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
    //使用递归的方法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
        ListNode* pMergeList;
        if (l1->val < l2->val)
        {
            pMergeList = l1;
            pMergeList->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            pMergeList = l2;
            pMergeList->next = mergeTwoLists(l1, l2->next);
        }

        return pMergeList;
    }
protected:
private:
};