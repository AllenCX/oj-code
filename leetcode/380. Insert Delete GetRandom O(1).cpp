class RandomizedSet {
public:
    unordered_map<int, int> mp; // map a val to its index
    vector<int> v;
    long int num = 0;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            v.push_back(val);
            mp[val] = v.size() - 1;
            return true;
        }else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int last = v.back();
            v[mp[val]] = last;
            v.pop_back();
            mp[last] = mp[val];
            mp.erase(val);
            return true;
        }else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

 #include <stdlib.h>
#include <time.h>
class RandomizedSet {
public:
    unordered_set<int> randomSet;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(randomSet.find(val) == randomSet.end()){
            randomSet.insert(val);
            return true;
        }else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(randomSet.find(val) != randomSet.end()){
            randomSet.erase(val);
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(randomSet.size() == 0) return 0;
        unordered_set<int>::iterator it = randomSet.begin();
        advance(it, rand() % randomSet.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */