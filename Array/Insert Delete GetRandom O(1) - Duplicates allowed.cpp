class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand((unsigned)time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = mp.find(val) == mp.end();
        mp[val].push_back(values.size());
        values.emplace_back(val, mp[val].size()-1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool res = mp.find(val) != mp.end();
        if (res) {
            auto last = values.back();
            mp[last.first][last.second] = mp[val].back();
            values[mp[val].back()] = last;
            values.pop_back();
            mp[val].pop_back();
            if (mp[val].empty()) mp.erase(val);
        }
        return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return values[rand() % values.size()].first;
    }
private:
    unordered_map<int, vector<int>> mp;
    vector<pair<int,int>> values;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */