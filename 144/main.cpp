#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *ptr = root;
        vector<int> ans;
        while (!s.empty() || ptr != NULL)
        {
            if (ptr != NULL)
            {
                ans.push_back(ptr->val);
                if (ptr->right != NULL)
                    s.push(ptr->right);
                ptr = ptr->left;
            }
            else
            {
                ptr = s.top();
                s.pop();
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    Solution s;
    vector<int> ret = s.preorderTraversal(n1);
    for (auto num : ret)
        cout << num << ' ';
    cout << endl;
    return 0;
}