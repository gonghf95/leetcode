#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *build(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = build(nums, l, mid);
            root->right = build(nums, mid + 1, r);
            return root;
        }
        return NULL;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return NULL;
        return build(nums, 0, nums.size());
    }
};

void Print(TreeNode *root)
{
    if (root == NULL)
        return;
    Print(root->left);
    cout << root->val << '\t';
    Print(root->right);
}

int main(int argc, char *argv[])
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *ret = s.sortedArrayToBST(nums);
    Print(ret);
    cout << endl;
    return 0;
}