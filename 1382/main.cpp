#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct AvlTree
{
    int val;
    AvlTree *left;
    AvlTree *right;
    int height;
    AvlTree(int x) : val(x), left(NULL), right(NULL), height(0) {}
};

void PrintTree(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        while (size-- > 0)
        {
            TreeNode *tmp = que.front();
            que.pop();
            if (tmp != NULL)
            {
                cout << tmp->val << ',';
                que.push(tmp->left);
                que.push(tmp->right);
            }
            else
                cout << "null,";
        }
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> vi;
    map<TreeNode *, int> mti;

    int Height(AvlTree *node)
    {
        return node == NULL ? 0 : node->height;
    }

    AvlTree *rotateLeft(AvlTree *node)
    {
        AvlTree *right;
        right = node->right;
        node->right = right->left;
        right->left = node;

        node->height = max(Height(node->left), Height(node->right)) + 1;
        right->height = max(Height(node->left), Height(node->right)) + 1;

        return right;
    }

    AvlTree *rotateRight(AvlTree *node)
    {
        AvlTree *left;
        left = node->left;
        node->left = left->right;
        left->right = node;

        node->height = max(node->left->height, node->right->height) + 1;
        left->height = max(left->left->height, left->right->height) + 1;

        return left;
    }

    AvlTree *Insert(int X, AvlTree *T)
    {
        if (T == NULL)
        {
            T = new AvlTree(X);
        }
        else if (X < T->val)
        {
            T->left = Insert(X, T->left);
            int rh = Height(T->right);
            int lh = Height(T->left);
            if (lh - rh > 1)
                T = rotateRight(T);
            else if (rh - lh > 1)
            {
                T->left = rotateLeft(T->left);
                T = rotateRight(T);
            }
        }
        else if (X > T->val)
        {
            T->right = Insert(X, T->right);
            int rh = Height(T->right);
            int lh = Height(T->left);
            if (rh - lh > 1)
                T = rotateLeft(T);
            else if (lh - rh > 1)
            {
                T->right = rotateRight(T->right);
                T = rotateLeft(T);
            }
        }
        T->height = max(Height(T->left), Height(T->right)) + 1;
        return T;
    }

    void build(AvlTree *tree, TreeNode *&root)
    {
        if (tree == NULL)
            return;
        root = new TreeNode(tree->val);
        build(tree->left, root->left);
        build(tree->right, root->right);
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == NULL)
            return root;

        AvlTree *tree = NULL;
        TreeNode *node = root;
        stack<TreeNode *> st;
        while (node != NULL || !st.empty())
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                node = st.top();
                st.pop();
                tree = Insert(node->val, tree);
                node = node->right;
            }
        }

        TreeNode *ret = NULL;
        build(tree, ret);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    // TreeNode *n1 = new TreeNode(1);
    // TreeNode *n2 = new TreeNode(2);
    // TreeNode *n3 = new TreeNode(3);
    // TreeNode *n4 = new TreeNode(4);
    // n1->right = n2;
    // n2->right = n3;
    // n3->right = n4;
    // PrintTree(n1);

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(15);
    TreeNode *n3 = new TreeNode(14);
    TreeNode *n4 = new TreeNode(17);
    TreeNode *n5 = new TreeNode(7);
    TreeNode *n6 = new TreeNode(2);
    TreeNode *n7 = new TreeNode(12);
    TreeNode *n8 = new TreeNode(3);
    TreeNode *n9 = new TreeNode(9);
    TreeNode *n10 = new TreeNode(11);
    n1->right = n2;
    n2->left = n3;
    n2->right = n4;
    n3->left = n5;
    n5->left = n6;
    n5->right = n7;
    n6->right = n8;
    n7->left = n9;
    n9->right = n10;
    PrintTree(n1);

    Solution s;
    TreeNode *ret = s.balanceBST(n1);
    PrintTree(ret);
    return 0;
}