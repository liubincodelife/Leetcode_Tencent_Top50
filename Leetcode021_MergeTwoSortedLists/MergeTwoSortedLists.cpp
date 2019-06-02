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

    //使用迭代的方法
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
    {
        ListNode* preHead = new ListNode(-1);  //需要考虑内存释放问题！！！
        ListNode* pNode = preHead;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                pNode->next = l1;
                l1 = l1->next;
            } 
            else
            {
                pNode->next = l2;
                l2 = l2->next;
            }
            pNode = pNode->next;
        }

        pNode->next = (l1 == nullptr) ? l2 : l1;

        return preHead->next;
    }
protected:
private:
};

int main(int argc, char** argv)
{

    getchar();
    return 0;
}