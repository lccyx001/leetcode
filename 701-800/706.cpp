#include <unordered_map>
using namespace std;

class MyHashMap
{
private:
    unordered_map<int, int> m;

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        if (this->m.count(key) == 0)
            this->m.insert({key, value});
        else
        {
            this->m.erase(key);
            this->m.insert({key, value});
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        unordered_map<int, int>::iterator i;
        i = this->m.find(key);
        if (i == this->m.end())
            return -1;

        return i->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        this->m.erase(key);
    }
};