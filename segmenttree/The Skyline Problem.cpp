class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    	vector<pair<int, int>> res;
        vector<pair<int, int>> heights;
        for (vector<int> b : buildings) {
        	heights.emplace_back(b[0], -b[2]);
        	heights.emplace_back(b[1], b[2]);
        }
        sort(heights.begin(), heights.end());
        multiset<int> mt;
        mt.insert(0);
        for (auto it : heights) {
        	if (it.second < 0) {
        		mt.insert(-it.second);
        	} else {
        		mt.erase(mt.find(it.second));
        	}
        	int h = mt.empty() ? 0 : *mt.rbegin();
        	if (res.empty() || res.back().second != h) res.push_back({it.first, h});
        }
        return res;
    }
};