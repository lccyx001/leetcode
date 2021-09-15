#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    // if (ransomNote.size() > magazine.size())
    //     return false;

    // unordered_map<char, int> mi;
    // for (int i = 0; i < magazine.size(); i++)
    // {
    //     if (mi.count(magazine[i]))
    //         mi[magazine[i]]++;
    //     else
    //         mi[magazine[i]] = 1;
    // }

    // for (int i = 0; i < ransomNote.size(); i++)
    // {
    //     if (mi[ransomNote[i]] <= 0)
    //         return false;
    //     mi[ransomNote[i]]--;
    // }
    // return true;
    for (int i = 0; i < ransomNote.size(); i++)
    {
        int a = magazine.find(ransomNote[i]);
        if (a != -1)
        {
            magazine[a] = '0';
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a = "aa", b = "ab";
    cout << canConstruct(a, b);
}