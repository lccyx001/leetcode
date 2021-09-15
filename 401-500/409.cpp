#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
int longestPalindrome(string s)
{
    unordered_map<char, int> count;
    int ans = 0;
    for (char c : s)
        ++count[c];
    for (auto p : count)
    {
        int v = p.second;
        ans += v / 2 * 2;
        if (v % 2 == 1 and ans % 2 == 0)
            ++ans;
    }
    return ans;

    // int n = s.size();
    // unordered_map<char, int> um;
    // for (int i = 0; i < n; i++)
    // {
    //     if (um.count(s[i]))
    //         um[s[i]]++;
    //     else
    //         um[s[i]] = 1;
    // }
    // int max_odd = 0, max_len = 0;

    // for (auto &p : um)
    // {
    //     cout << p.first << "  " << p.second << endl;
    //     if (p.second % 2 == 0)
    //         max_len += p.second;
    //     else
    //     {
    //         if (p.second != 1)
    //             max_len += p.second - 1;
    //         max_odd = max_odd > p.second ? max_odd : p.second;
    //     }
    // }
    // if (max_odd > 0)
    //     max_len++;

    // return max_len;
}

int main()
{
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout << longestPalindrome(s) << endl;
    // cout << 'z' - 'A';
}