#include <iostream>

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
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        treeSum(root, sum);
        return root;
    }

    void treeSum(TreeNode *root, int &sum)
    {
        if (root != NULL)
        {
            treeSum(root->right, sum);
            sum += root->val;
            root->val = sum;
            treeSum(root->left, sum);
        }
    }
};

void PrintTree(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->val << ",";
        PrintTree(root->left);
        PrintTree(root->right);
    }
    else
        cout << "null,";
}

int main(int argc, char *argv[])
{
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(1);
    TreeNode *n3 = new TreeNode(6);
    TreeNode *n4 = new TreeNode(0);
    TreeNode *n5 = new TreeNode(2);
    TreeNode *n6 = new TreeNode(5);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(3);
    TreeNode *n9 = new TreeNode(8);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->right = n8;
    n3->left = n6;
    n3->right = n7;
    n7->right = n9;

    PrintTree(n1);
    cout << endl;

    Solution s;
    TreeNode *ret = s.bstToGst(n1);
    PrintTree(ret);
    cout << endl;
    return 0;
}