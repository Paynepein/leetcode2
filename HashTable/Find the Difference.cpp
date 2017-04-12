class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (char c : s) ans ^= (int)c;
        for (char c : t) ans ^= (int)c;
        return (char)ans;
    }
};