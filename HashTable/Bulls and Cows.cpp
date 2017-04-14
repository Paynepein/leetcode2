class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        int a = 0, b = 0;
        for (int i = 0; i < guess.size(); ++i) {
        	if (secret[i] == guess[i]) ++a;
        	else {
        		++mp[secret[i]];
        	}
        }
        for (int i = 0; i < guess.size(); ++i) {
        	if (secret[i] != guess[i] && mp[guess[i]]-- > 0) {
        		++b;
        	}
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};