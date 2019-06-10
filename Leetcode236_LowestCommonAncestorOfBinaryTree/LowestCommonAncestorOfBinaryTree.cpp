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
        //������Ҷ�ӽڵ㣬ֱ�ӷ���nullptr
        if (root == nullptr)
            return root;
        //������p��q�ڵ㣬��ֱ�ӷ���p����q
        if (root == p || root == q)
            return root;

        TreeNode* pLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* pRight = lowestCommonAncestor(root->right, p, q);
        //���pLeft��pRight����Ϊ�գ���֤��p��q�ֱ��ڸ��ڵ�����࣬���ڵ㼴Ϊ��������
        if (pLeft != nullptr && pRight != nullptr)
            return root;
        //���ֻ��pLeft��Ϊ�գ���֤��������������������p����q�ڵ㣬�˽ڵ㼴Ϊ��������
        else if (pLeft != nullptr)
            return pLeft;
        //���ֻ��pRight��Ϊ�գ���֤��������������������p����q�ڵ㣬�˽ڵ㼴Ϊ��������
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