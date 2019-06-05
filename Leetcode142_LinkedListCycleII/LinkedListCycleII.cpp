#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

//此方案在Leetcode上超时
class Solution1
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return nullptr;
        //1.得到环内相遇的节点
        ListNode* pMeetNode = GetMeetingNode(head);
        if (pMeetNode == nullptr)
            return nullptr;
        //2.计算环内节点数目
        ListNode* pNode1 = head;
        int count = 1;
        while (pNode1->next != pMeetNode)
        {
            ++count;
            pNode1 = pNode1->next;
        }
        //3.将pNode1向后移动count步
        pNode1 = head;
        for (int i = 0; i < count; ++i)
        {
            pNode1 = pNode1->next;
        }

        //4.将pNode1和pNode2一起向后每次移动1步，当两个指针相遇时即为环的入口节点
        ListNode* pNode2 = head;
        while (pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }

        return pNode1;
    }

    ListNode* GetMeetingNode(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return nullptr;
        bool state = false;
        ListNode* pSlowNode = head->next;
        ListNode* pFastNode = pSlowNode->next;
        
        while (pFastNode != nullptr && pSlowNode != nullptr)
        {
            if (pFastNode == pSlowNode)
                return pFastNode;
            pSlowNode = pSlowNode->next;  //pSlowNode向后移动一步
            pFastNode = pSlowNode->next;  //pFastNode向后移动两步
            if (pFastNode->next != nullptr)
                pFastNode = pFastNode->next;
        }

        return nullptr;
    }
protected:
private:
};

class Solution2
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* pSlowNode = head;
        ListNode* pFastNode = head;
        bool hasCycle = false;
        while (pFastNode && pFastNode->next != nullptr)
        {
            pSlowNode = pSlowNode->next;
            pFastNode = pFastNode->next->next;
            if (pSlowNode == pFastNode)
            {
                hasCycle = true;
                break;
            }  
        }

        if (hasCycle)
        {
            pSlowNode = head;
            while (pSlowNode != pFastNode)
            {
                pSlowNode = pSlowNode->next;
                pFastNode = pFastNode->next;
            }

            return pFastNode;
        }
        else
        {
            return nullptr;
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