class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (grid[i][j] == 1) {
        			ans += getlandPerimeter(grid, i, j);
        		}
        	}
        }
        return ans;
    }

    int getlandPerimeter(vector<vector<int>>& grid, int i, int j) {
    	int conn = 0;
    	int m = grid.size(), n = grid[0].size();
    	if (i > 0 && grid[i-1][j] == 1) ++conn;
    	if (j > 0 && grid[i][j-1] == 1) ++conn;
    	if (i < m-1 && grid[i+1][j] == 1) ++conn;
    	if (j < n-1 && grid[i][j+1] == 1) ++conn;
    	return 4 - conn;
    }
};