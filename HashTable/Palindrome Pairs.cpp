class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if (words.size() < 2) return res;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); ++i) mp[words[i]] = i;
        for (int i = 0; i < words.size(); ++i) {
        	int len = words[i].size();
        	for (int j = 0; j <= len; ++j) {
        		string left = words[i].substr(0, j);
        		string right = words[i].substr(j);
        		string leftReverse = left;
        		string rightReverse = right;
        		reverse(leftReverse.begin(), leftReverse.end());
        		reverse(rightReverse.begin(), rightReverse.end());

        		if (isPalindrome(left) && mp.count(rightReverse) == 1 && mp[rightReverse] != i) {
        			res.push_back({mp[rightReverse], i});
        		}

        		if (right != "" && isPalindrome(right) && mp.count(leftReverse) == 1 && mp[leftReverse] != i) {
        			res.push_back({i, mp[leftReverse]});
        		}
        	}
        }
        return res;
    }

    bool isPalindrome(string str) {
    	if (str.size() <= 1) return true;
    	int len = str.size();
    	for (int i = 0; i < len / 2; ++i) {
    		if (str[i] != str[len - i - 1]) return false;
    	}
    	return true;
    }
};