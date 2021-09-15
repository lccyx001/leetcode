#include <iostream>
#include <set>
using namespace std;
class MyHashSet
{
private:
    set<int> s;

public:
    /** Initialize your data structure here. */

    MyHashSet()
    {
    }

    void add(int key)
    {
        this->s.insert(key);
    }

    void remove(int key)
    {
        this->s.erase(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return this->s.count(key) != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */