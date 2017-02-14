class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> mp;
        return wordBreakHelper(s, wordDict, mp);
    }

    vector<string> wordBreakHelper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& mp) {
        if (mp.find(s) != mp.end()) return mp[s];
        vector<string> res;
        for (int i = 1; i < s.size(); ++i) {
            string sub = s.substr(0, i);
            if (find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                for (string sb : wordBreakHelper(s.substr(i), wordDict, mp)) {
                    res.push_back(sub + " " + sb);
                }
            }
        }
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) {
            res.push_back(s);
        }
        mp[s] = res;
        return res;
    }
};