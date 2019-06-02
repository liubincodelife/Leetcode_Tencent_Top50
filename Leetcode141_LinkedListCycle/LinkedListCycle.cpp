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
        if (pSlow == nullptr)  //�������ֻ��һ���ڵ㣬ֱ�ӷ���false
            return false;

        ListNode* pFast = pSlow->next;
        while (pFast != nullptr && pSlow != nullptr)
        {
            if (pFast == pSlow)
                return true;
            pSlow = pSlow->next;
            pFast = pSlow->next;
            if (pFast != nullptr)  //�ж��Ƿ��Ѿ��������β
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