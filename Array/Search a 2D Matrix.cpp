class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = m * n - 1;
        while (left <= right) {
        	int mid = right + left >> 1;
        	int i = mid / n, j = mid % n;
        	if (matrix[i][j] == target) return true;
        	else if (matrix[i][j] < target) left = mid + 1;
        	else right = mid - 1;
        }
        return false;
    }
};