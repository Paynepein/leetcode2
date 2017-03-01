class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size()-1; i >= 0 && c == 1; --i) {
        	digits[i] += 1;
        	c = digits[i] / 10;
        	digits[i] %= 10;
        }
        if (c == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};