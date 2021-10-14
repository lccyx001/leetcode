# 容器实用代码段

```cpp
// find some key or value
if (m.find(key) == m.end())
if (m.count(key))

//loop
for ( auto it = mymap.begin(); it != mymap.end(); ++it )
    std::cout << " " << it->first << ":" << it->second;

// print 
for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }

for (auto it = m.cbegin(); it != m.cend(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    }

// vector 
// init
vector<char> a1{'1', '0', '1', '0', '0'};
vector<vector<int>> dp(length, vector<int>(n, val));
// find
bool f = *find(vec.begin(),vec.end(),target)==target;
bool f = find(vec.begin(),vec.end(),target)==vec.end();
// count


```
