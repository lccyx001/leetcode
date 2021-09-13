# 字符串实用函数段

```cpp
void trim(string &s)
{
    if (s.empty())
        return;

    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}

void split(string s, vector<string> &v, string spacer)
{
    int pos1, pos2, n = spacer.length();
    pos1 = 0;
    pos2 = s.find(spacer);
    while (pos2 != string::npos)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + n;
        pos2 = s.find(spacer, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

void strip(string s){
    s.erase(remove(s.begin(),s.end(), ' '),s.end());
}

//toupper
#include <algorithm>
transform(strA.begin(), strA.end(), strA.begin(), ::toupper);  
```

| 功能       | append() | +=    | push_back() |
| :--------- | :------- | :---- | :---------- |
| 部分字符串 | √        | ×     | ×           |
| 迭代器范围 | √        | ×     | ×           |
| 返回值     | *this    | *this | none        |
| 字符数组   | √        | √     | ×           |
| 单个字符   | ×        | √     | √           |
| 全字符串   | √        | √     | ×           |
| cstring    | √        | √     | ×           |
