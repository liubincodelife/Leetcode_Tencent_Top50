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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pCurrentNode = head;
        ListNode* pPrevNode = nullptr;
        while (pCurrentNode != nullptr)
        {
            ListNode* pNextTemp = pCurrentNode->next;
            pCurrentNode->next = pPrevNode;
            pPrevNode = pCurrentNode;
            pCurrentNode = pNextTemp;
        }

        return pPrevNode;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}