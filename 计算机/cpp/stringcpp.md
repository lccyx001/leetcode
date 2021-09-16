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

bool find(char c,string s){
    return s.find(c) == string::npos;
}

//toupper
#include <algorithm>
transform(strA.begin(), strA.end(), strA.begin(), ::toupper);  

// char to int
s - '0'

// int to string
to_string(val);

// 单个字符判断空
for (auto &si : s)
{
    if (si != ' ')
        buf += si;
}

// string array
// 1.使用pointer
const char *colour[4] = { "Blue", "Red",
                             "Orange", "Yellow" };
for (int i = 0; i < 4; i++)
    std::cout << colour[i] << "\n";

// 2.使用2维数组
char colour[4][10] = { "Blue", "Red", "Orange",
                        "Yellow" };
for (int i = 0; i < 4; i++)
    std::cout << colour[i] << "\n";

// 3.使用string类
std::string colour[4] = { "Blue", "Red",
                              "Orange", "Yellow" };
for (int i = 0; i < 4; i++)
    std::cout << colour[i] << "\n";

// 4.vector
std::vector<std::string> colour {"Blue", "Red", "Orange"};

colour.push_back("Yellow");

for (int i = 0; i < colour.size(); i++)
    std::cout << colour[i] << "\n";
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
