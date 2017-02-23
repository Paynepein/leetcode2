class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int count1 = 0, count2 = 0, i = 0, j = 0;
        while (count1 < n1) {
            if (s1[i] == s2[j]) {
                if (++j == s2.size()) {
                    ++count2;
                    j = 0;
                }
            }
            if (++i == s1.size()) {
                ++count1;
                i = 0;
            }
        }
        return count2 / n2;
    }
};