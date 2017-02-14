class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if (matrix.size() == 0) return 0;
    	int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n+1, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (matrix[i][j] == '1') ++heights[j];
        		else heights[j] = 0;
        	}
        	res = max(res, maximalSquareHelper(heights));
        }
        return res;
    }

    int maximalSquareHelper(vector<int>& heights) {
    	int n = heights.size();
    	stack<int> st;
    	int res = 0;
    	for (int i = 0; i < n; ++i) {
    		while (!st.empty() && heights[i] < heights[st.top()]) {
    			int index = st.top();
    			st.pop();
    			int last = st.empty() ? -1 : st.top();
    			res = max(res, (int)pow(min(heights[index], i - last - 1), 2));
    		}
    		st.push(i);
    	}
    	return res;
    }
};