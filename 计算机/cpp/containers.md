# 容器实用代码段

```cpp

// unordered map
if (m.find(key) == m.end())
if (m.count())

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
// find
bool f = *find(vec.begin(),vec.end().target)==target;

// count


```
