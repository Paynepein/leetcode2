class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	if (numRows == 0) return vector<vector<int>>(0);
        vector<vector<int>> res = {{1}};
        --numRows;
        for (int i = 0; i < numRows; ++i) {
        	vector<int> vec = res.back(), tmp = {1};
        	for (int i = 1; i < vec.size(); ++i) {
        		tmp.push_back(vec[i] + vec[i-1]);
        	}
        	tmp.push_back(1);
        	res.push_back(tmp);
        }
        return res;
    }
};