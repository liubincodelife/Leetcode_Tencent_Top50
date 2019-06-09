#include <iostream>
#include <algorithm>

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
    //�ݹ鷨
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int leftHeight = maxDepth(root->left);
            int rightHeight = maxDepth(root->right);

            return (max(leftHeight, rightHeight) + 1);
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