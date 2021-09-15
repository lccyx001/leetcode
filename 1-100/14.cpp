#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    int smin=200;
    for(int i=0;i<strs.size();i++){
        if(strs[i].length()<smin) smin = strs[i].length();
    }
    string ans;
    for(int i=0;i<smin;i++){
        char a=strs[0][i];
        for(int j=1;j<strs.size();j++){
            if(a!=strs[j][i]) return ans;
        }
        ans+=a;
    }
    return ans;
}