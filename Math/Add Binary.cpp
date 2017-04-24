class Solution {
public:
    string addBinary(string a, string b) {
    	int i = a.size(), j = b.size(), c = 0;
        string ans(max(i, j), '0');
        while (i > 0 || j > 0) {
            --i, --j;
        	int n1 = i >= 0 ? a[i]-'0' : 0, n2 = j >= 0 ? b[j]-'0' : 0;
        	ans[max(i, j)] += (n1 + n2 + c) % 2;
        	c = (n1 + n2 + c) / 2;
        }
        if (c > 0) ans = '1' + ans;
        return ans;
    }
};