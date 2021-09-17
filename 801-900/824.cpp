#include <string>
#include <vector>
#include <iostream>
using namespace std;
string toGoatLatin(string sentence)
{
    int sn = sentence.size(), cnt = 0;
    string aeo = "aeiouAEIOU";
    string word = "", ans = "";
    sentence += " ";

    for (auto &alpha : sentence)
    {
        if (alpha == ' ')
        {
            if (word.size() == 0)
                continue;
            cnt++;
            if (aeo.find(word[0]) != string::npos)
                word += "ma";
            else
            {
                word = word.substr(1) + word[0] + "ma";
            }
            string tail(cnt, 'a');
            ans += word + tail + ' ';
            word = "";
        }
        else
        {
            word += alpha;
        }
    }
    if (ans[ans.size() - 1] == ' ')
        return ans.substr(0, ans.size() - 1);

    return ans;
}

int main()
{
    string a = "I speak Goat Latin";
    string b = "I speak Goat Latin ";
    string c = " I speak Goat Latin ";
    cout << toGoatLatin(a);
}