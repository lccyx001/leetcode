#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
void countWords(string s, unordered_map<string, int> &um)
{
    string word = "";
    for (auto &si : s)
    {
        if (si != ' ')
            word += si;
        else
        {
            if (word == "")
                continue;
            um[word]++;
            word = "";
        }
    }
    if (word.size() > 0)
        um[word]++;
}

vector<string> uncommonFromSentences(string s1, string s2)
{
    unordered_map<string, int> um;
    countWords(s1, um);
    countWords(s2, um);
    vector<string> vec;
    for (auto &umpair : um)
    {
        if (umpair.second == 1)
            vec.push_back(umpair.first);
    }
    return vec;
}

int main()
{
    string s1 = "", s2 = " ";
    vector<string> v = uncommonFromSentences(s1, s2);
    for (auto &vi : v)
    {
        cout << vi << endl;
    }
}