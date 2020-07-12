#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct TireNode
{
    char val;
    bool isEnd;
    TireNode *child[26];

    TireNode(char x) : val(x), isEnd(false)
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TireNode(-1);
    }

    ~Trie()
    {
        while (!que.empty())
        {
            TireNode *tmp = que.front();
            que.pop();
            delete tmp;
        }
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TireNode *ptr = root;
        for (unsigned int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if (ptr->child[ch] == NULL)
            {
                ptr->child[ch] = new TireNode(word[i]);
                que.push(ptr->child[ch]);
            }
            ptr = ptr->child[ch];
        }
        ptr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TireNode *ptr = root;
        unsigned int i = 0;
        while (i < word.size())
        {
            int ch = word[i] - 'a';
            if (ptr->child[ch] == NULL)
                break;
            ptr = ptr->child[ch];
            i++;
        }
        if (i != word.size())
            return false;
        return ptr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TireNode *ptr = root;
        unsigned int i = 0;
        while (i < prefix.size())
        {
            int ch = prefix[i] - 'a';
            if (ptr->child[ch] == NULL)
                break;
            ptr = ptr->child[ch];
            i++;
        }
        if (i != prefix.size())
            return false;
        return true;
    }

private:
    TireNode *root;
    queue<TireNode *> que;
};

int main(int argc, char *argv[])
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 返回 true
    cout << trie.search("app") << endl;     // 返回 false
    cout << trie.startsWith("app") << endl; // 返回 true
    trie.insert("app");
    cout << trie.search("app") << endl; // 返回
    return 0;
}