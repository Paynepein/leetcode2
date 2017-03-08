class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        int m = triangle.size();
    	vector<int> totalVec(triangle.back().size(), INT_MAX);
        totalVec[0] = triangle[0][0];
        for (int i = 1; i < m; ++i) {
            for (int j = i; j > 0; --j) {
                totalVec[j] = min(totalVec[j], totalVec[j-1]) + triangle[i][j];
            }
            totalVec[0] += triangle[i][0];
        }
        int res = totalVec[0];
        for (int n : totalVec) {
            res = min(res, n);
        }
        return res;
    }
};