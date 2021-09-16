#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    unordered_map<int, vector<string>> mp;
    int n1 = list1.size(), n2 = list2.size(), mi = 1001;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (list1[i] == list2[j])
                mp[i + j].push_back(list1[i]);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->first < mi)
            mi = it->first;

    return mp[mi];
}