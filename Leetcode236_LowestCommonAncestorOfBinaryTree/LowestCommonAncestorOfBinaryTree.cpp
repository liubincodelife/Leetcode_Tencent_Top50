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
        //当遇到叶子节点，直接返回nullptr
        if (root == nullptr)
            return root;
        //若遇到p和q节点，则直接返回p或者q
        if (root == p || root == q)
            return root;

        TreeNode* pLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* pRight = lowestCommonAncestor(root->right, p, q);
        //如果pLeft和pRight都不为空，则证明p和q分别在根节点的两侧，根节点即为公共祖先
        if (pLeft != nullptr && pRight != nullptr)
            return root;
        //如果只有pLeft不为空，则证明在树的左子树遇到了p或者q节点，此节点即为公共祖先
        else if (pLeft != nullptr)
            return pLeft;
        //如果只有pRight不为空，则证明在树的右子树遇到了p或者q节点，此节点即为公共祖先
        else if (pRight != nullptr)
            return pRight;

        return nullptr;
    }
protected:
private:
};

int main(int argc, char** argv)
{

    getchar();
    return 0;
}