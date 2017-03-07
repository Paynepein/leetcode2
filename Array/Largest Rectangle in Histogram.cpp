class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
        	while (!st.empty() && heights[st.top()] > heights[i]) {
        		int h = heights[st.top()];
        		st.pop();
        		int last = st.empty() ? -1 : st.top();
        		res = max(res, h * (i - last - 1));
        	}
        	st.push(i);
        }
        return res;
    }
};