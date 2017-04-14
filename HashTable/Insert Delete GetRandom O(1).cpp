class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((int)time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val) == 1) return false;
        vals.push_front(val);
        mp[val] = vals.begin();
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val) == 0) return false;
        vals.erase(mp[val]);
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % vals.size();
        return *(next(vals.begin(), index));
    }
private:
    list<int> vals;
    unordered_map<int, list<int>::iterator> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */