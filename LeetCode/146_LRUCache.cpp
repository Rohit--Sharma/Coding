#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (hash_map.find(key) != hash_map.end()) {
            int val = (hash_map[key]).first;
            cache.erase(hash_map[key].second);
            cache.push_front(key);
            hash_map[key] = { val, cache.begin() };
            return val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (hash_map.find(key) == hash_map.end()) {
            if (cache.size() >= _capacity) {
                hash_map.erase(cache.back());
                cache.pop_back();
            }
        }
        else
            cache.erase(hash_map[key].second);

        cache.push_front(key);
        hash_map[key] = { value, cache.begin() };
    }

private:
    list<int> cache;
    map<int, pair<int, list<int>::iterator>> hash_map;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
    LRUCache obj = LRUCache(2);
    obj.put(1, 1);
    obj.put(2, 2);
    cout << obj.get(1) << endl;
    obj.put(3, 3);
    cout << obj.get(2) << endl;
    obj.put(4, 4);
    cout << obj.get(1) << endl;
    cout << obj.get(3) << endl;
    cout << obj.get(4) << endl;

    return 0;
}