class RandomizedCollection {
public:
    unordered_map<int, vector<int>> mp;
    vector<pair<int, int>> nums;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            nums.push_back(pair<int, int>(val, 0));
            vector<int> v;
            v.push_back(nums.size() - 1);
            mp[val] = v;
            return true;
        }else{
            nums.push_back(pair<int, int>(val, mp[val].size()));
            mp[val].push_back(nums.size() - 1);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            pair<int, int> last = nums.back();
            mp[last.first][last.second] = mp[val].back();
            nums[mp[val].back()] = last;
            mp[val].pop_back();
            if(mp[val].empty()) mp.erase(val);
            nums.pop_back();
            return true;
        }else{
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */