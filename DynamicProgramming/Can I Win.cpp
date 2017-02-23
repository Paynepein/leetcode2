class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (sum < desiredTotal) return false;
        vector<bool> avalibles(maxChoosableInteger + 1, true);
        unordered_map<int, bool> mp;
        return canIWinHelper(avalibles, desiredTotal, mp);
    }

    bool canIWinHelper(vector<bool>& avalibles, int desiredTotal, unordered_map<int, bool>& mp) {
        int curr = 0;
        for (int i = 1; i <= avalibles.size(); ++i) {
            curr |= int(avalibles[i]) << i;
        }
        if (mp.find(curr) != mp.end()) {
            return mp[curr];
        }
        for (int i = avalibles.size()-1; i >= 1; --i) {
            if (avalibles[i]) {
                avalibles[i] = false;
                if (i >= desiredTotal || !canIWinHelper(avalibles, desiredTotal - i, mp)) {
                    avalibles[i] = true;
                    mp[curr] = true;
                    return true;
                }
                avalibles[i] = true;
            }
        }
        mp[curr] = false;
        return false;
    }
};