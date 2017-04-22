class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res(num1.size() + num2.size(), '0');
        int a = 0, b = 0, c = 0;
        for (int i = num2.size()-1; i >= 0; --i) {
        	a = num2[i] - '0';
        	c = 0;
        	for (int j = num1.size()-1; j >= 0; --j) {
        		b = a * (num1[j] - '0');
        		b = res[i+j+1] - '0' + b + c;
        		c = b / 10;
        		res[i+j+1] = b % 10 + '0';
        	}
            if (c > 0) res[i] = c + '0';
        }
        return c > 0 ? res : res.substr(1);
    }
};