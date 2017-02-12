class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if (matrix.size() == 0) return 0;
    	int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n+1, 0);
        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (matrix[i][j] == '1') ++heights[j];
        		else heights[j] = 0;
        	}
        	maxArea = max(maxArea, maxAreaCal(heights));
        }
        return maxArea;
    }

    int maxAreaCal(vector<int>& heights) {
    	stack<int> st;
    	int res = 0;
    	for (int i = 0; i < heights.size(); ++i) {
    		while (!st.empty() && heights[st.top()] > heights[i]) {
    			int h = heights[st.top()];
    			st.pop();
    			int index =  st.empty() ? -1 : st.top();
    			res = max(res, (i - index - 1) * h);
    		}
    		st.push(i);
    	}
    	return res;
    }
};