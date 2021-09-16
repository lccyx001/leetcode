#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int uniqueMorseRepresentations(vector<string> &words)
{
    string mapping[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    set<string> transset;
    for (auto &w : words)
    {
        string trans = "";
        for (auto &alp : w)
        {
            trans += mapping[alp - 'a'];
        }
        cout << trans << endl;
        transset.insert(trans);
    }
    return transset.size();
}

int main()
{
    vector<string> words = {"gin",
                            "zen",
                            "gig",
                            "msg"};

    cout << uniqueMorseRepresentations(words);
}