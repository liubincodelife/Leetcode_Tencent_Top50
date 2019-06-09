#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //当两个节点在根节点两侧
        if (p->val <= root->val && q->val >= root->val || p->val >= root->val && q->val <= root->val)
            return root;
        else if (p->val <= root->val)
        {
            TreeNode* pNode = lowestCommonAncestor(root->left, p, q);
            return pNode;
        }
        else
        {
            TreeNode* pNode = lowestCommonAncestor(root->right, p, q);
            return pNode;
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