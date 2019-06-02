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
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr)
            return false;
        ListNode* pSlow = head->next;
        if (pSlow == nullptr)  //如果链表只有一个节点，直接返回false
            return false;

        ListNode* pFast = pSlow->next;
        while (pFast != nullptr && pSlow != nullptr)
        {
            if (pFast == pSlow)
                return true;
            pSlow = pSlow->next;
            pFast = pSlow->next;
            if (pFast != nullptr)  //判断是否已经到链表结尾
            {
                pFast = pFast->next;
            }
        }

        return false;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}