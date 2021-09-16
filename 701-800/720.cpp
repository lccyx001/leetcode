#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class TireNode
{
public:
    unordered_map<char, TireNode *> children;
    bool word;
    TireNode() : word(false){};
    void insert(string word, TireNode *root)
    {
        TireNode *p = root;
        for (char &s : word)
        {
            if (!p->children.count(s))
                p->children[s] = new TireNode();
            p = p->children[s];
        }
        p->word = true;
    }
};

bool dfs(string word, TireNode *root)
{
    TireNode *p = root;
    for (char &s : word)
    {
        if (p->children.count(s) && p->children[s]->word)
            p = p->children[s];
        else
            return false;
    }
    return true;
}

string longestWord(vector<string> &words)
{
    string ans = "";
    TireNode *root = new TireNode();
    for (string &word : words)
        root->insert(word, root);

    for (string &word : words)
    {
        if (dfs(word, root))
        {
            if (ans.size() < word.size())
            {
                ans = word;
                continue;
            }
            if (ans.size() == word.size() && ans > word)
            {
                ans = word;
                continue;
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> vec;
    // ["a","banana","app","appl","ap","apply","apple"]
    vec.push_back("a");
    vec.push_back("banana");
    vec.push_back("app");
    vec.push_back("appl");
    vec.push_back("ap");
    vec.push_back("apply");
    vec.push_back("apple");

    string res = longestWord(vec);
    cout << res;
}