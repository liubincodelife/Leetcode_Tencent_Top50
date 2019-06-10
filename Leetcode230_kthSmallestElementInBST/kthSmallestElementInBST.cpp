#include <iostream>
#include <vector>

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
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> nums;
        InOrderTraverse(root, nums, k);
        return nums[k - 1];
    }

    void InOrderTraverse(TreeNode* root, vector<int>& nums, int k)
    {
        //��������Ҷ�ӽڵ��������Ĵ�С����k������
        if (root == nullptr || nums.size() == k)
            return;
        InOrderTraverse(root->left, nums, k);
        nums.push_back(root->val);
        InOrderTraverse(root->right, nums, k);
    }
protected:
private:
};

int main(int argc, char** argv)
{
    getchar();
    return 0;
}