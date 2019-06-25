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
    int pathSum = INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        maxPathSumCore(root);
        return pathSum;
    }

    int maxPathSumCore(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int leftMax = max(maxPathSumCore(root->left), 0);
        int rightMax = max(maxPathSumCore(root->right), 0);

        int newPathSum = root->val + leftMax + rightMax;
        if (newPathSum > pathSum)
            pathSum = newPathSum;

        return root->val + max(leftMax, rightMax);
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}