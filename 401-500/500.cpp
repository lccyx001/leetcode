#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;
vector<string> findWords(vector<string> &words)
{
    // 实用容器保存三种字符
    // 遍历每个单词，使用变量kind代表该单词所出现的单词种类，如果种类有变化，返回false
    vector<string> res;
    string line1 = "qwertyuiopQWERTYUIOP", line2 = "asdfghjklASDFGHJKL", line3 = "zxcvbnmZXCVBNM";
    for (int i = 0; i < words.size(); i++)
    {
        int n1 = 0, n2 = 0, n3 = 0;
        int length = words[i].length();
        for (int j = 0; j < length; j++)
        {
            if (line1.find(words[i][j]) != string::npos)
            {
                n1++;
            }
            else if (line2.find(words[i][j]) != string::npos)
            {
                n2++;
            }
            else if (line3.find(words[i][j]) != string::npos)
            {
                n3++;
            }
        }
        if (n1 == length || n2 == length || n3 == length)
        {
            res.push_back(words[i]);
        }
    }

    return res;
}
