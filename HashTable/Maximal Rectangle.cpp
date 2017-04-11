class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
    	if (m == 0) return 0;
        vector<int> heights(n+1, 0);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (matrix[i][j] == '1') {
        			++heights[j];
        		} else {
        			heights[j] = 0;
        		}
        	}
        	ans = max(ans, maximalRectangleHelper(heights));
        }
        return ans;
    }

    int maximalRectangleHelper(vector<int>& heights) {
    	stack<int> st;
    	int ans = 0;
    	for (int i = 0; i < heights.size(); ++i) {
    		while (!st.empty() && heights[st.top()] > heights[i]) {
    			int last = st.top();
    			st.pop();
    			int w = st.empty() ? i : i - st.top() - 1, h = heights[last];
    			ans = max(ans, h * w);
    		}
    		st.push(i);
    	}
    	return ans;
    }
};