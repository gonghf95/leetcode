#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;
        int ans = 1;
        for (auto &child : root->children)
        {
            int ret = maxDepth(child);
            ans = max(ret + 1, ans);
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Node n1(1);
    Node n2(3);
    Node n3(2);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    n1.children.push_back(&n2);
    n1.children.push_back(&n3);
    n1.children.push_back(&n4);
    n2.children.push_back(&n5);
    n2.children.push_back(&n6);

    Solution s;
    cout << s.maxDepth(&n1) << endl;
    return 0;
}