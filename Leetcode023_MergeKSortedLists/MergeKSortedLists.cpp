#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct comp //��д�º���
{
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val; //С����
    }
};

class Solution
{
public:
    //�������ȼ����еķ����ϲ�
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, comp> listQueue;
        ListNode* prevHead = new ListNode(-1);
        ListNode* pNode = prevHead;
        for (ListNode* list : lists)
        {
            if (list != nullptr)
                listQueue.push(list);
        }

        while (!listQueue.empty())
        {
            ListNode* pTmpNode = listQueue.top();
            pNode->next = pTmpNode;
            listQueue.pop();
            pNode = pNode->next;
            if (pNode->next != nullptr)
                listQueue.push(pNode->next);
        }
        return prevHead->next;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}