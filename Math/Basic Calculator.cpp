class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0, sign = 1, res = 0;
        for (char c : s) {
        	if (c == '(') {
        		st.push(res);
        		st.push(sign);
        		res = 0;
        		sign = 1;
        	} else if (c == ')') {
        		res += num * sign;
        		sign = st.top();
        		st.pop();
        		res = st.top() + sign * res;
        		st.pop();
        		num = 0;
        		sign = 1;
        	} else if (c == '+') {
        		res += num * sign;
        		num = 0;
        		sign = 1;
        	} else if (c == '-') {
        		res += num * sign;
        		num = 0;
        		sign = -1;
        	} else if (isdigit(c)) {
        		num = num * 10 + c - '0';
        	}
        }
        if (num != 0) {
        	res += num * sign;
        }
        return res;
    }
};