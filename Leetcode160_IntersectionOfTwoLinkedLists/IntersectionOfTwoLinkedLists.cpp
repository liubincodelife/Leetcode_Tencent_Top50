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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* pNodeA = headA;
        ListNode* pNodeB = headB;
        while (pNodeA != pNodeB)
        {
            pNodeA = (pNodeA == nullptr) ? headB : pNodeA->next;
            pNodeB = (pNodeB == nullptr) ? headA : pNodeB->next;
        }

        return pNodeA;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}