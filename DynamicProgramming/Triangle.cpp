class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if (triangle.size() == 0) return 0;
        vector<int> dp1(triangle.size(), INT_MAX), dp2(triangle.size(), INT_MAX), *ptr1 = &dp1, *ptr2 = &dp2;
        dp1[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
        	ptr2->clear();
        	(*ptr2)[0] = triangle[i][0] + (*ptr1)[0];
        	for (int j = 1; j <= i; ++j) {
        		(*ptr2)[j] = triangle[i][j] + min((*ptr1)[j-1], (*ptr1)[j]);
        	}
        	swap(ptr1, ptr2);
        }
        int res = (*ptr1)[0];
        for (int i = 1; i < triangle.size(); ++i) {
        	res = min(res, (*ptr1)[i]);
        }
        return res;
    }
};