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
    //将需要删除节点的值赋值为下一节点的值并将下一节点删除
    void deleteNode(ListNode* node)
    {
        ListNode* pNextNode = node->next;
        node->val = pNextNode->val;
        node->next = pNextNode->next;
        delete pNextNode;
        pNextNode = nullptr;
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}