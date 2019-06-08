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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* pSumListDummyHead = new ListNode(0);  //定义哨兵节点
        ListNode* pNode = pSumListDummyHead;
        int carryOut = 0;
        while (l1 != nullptr || l2 != nullptr)  // 两个链表可能不同长度
        {
            int tmpNum1 = l1 == nullptr ? 0 : l1->val;
            int tmpNum2 = l2 == nullptr ? 0 : l2->val;

            int sum = tmpNum1 + tmpNum2 + carryOut;
            
            ListNode* tmpNode = new ListNode(0);
            tmpNode->val = sum % 10;
            pNode->next = tmpNode;
            pNode = pNode->next;
            carryOut = sum / 10;
            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }

        //考虑最高位相加有进位的情况
        if (carryOut > 0)
        {
            ListNode* tmpNode = new ListNode(carryOut);
            pNode->next = tmpNode;
        }

        return pSumListDummyHead->next;
    }
protected:
private:
};

void test(ListNode* pHead1, ListNode* pHead2)
{
    Solution solution;
    ListNode* pSumList = solution.addTwoNumbers(pHead1, pHead2);
}

void test1()
{
    ListNode* pHead1 = new ListNode(2);
    ListNode* pNode2 = new ListNode(4);
    ListNode* pNode3 = new ListNode(3);

    ListNode* pHead2 = new ListNode(5);
    ListNode* pNode4 = new ListNode(6);
    ListNode* pNode5 = new ListNode(4);

    pHead1->next = pNode2;
    pNode2->next = pNode3;

    pHead2->next = pNode4;
    pNode4->next = pNode5;

    test(pHead1, pHead2);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}