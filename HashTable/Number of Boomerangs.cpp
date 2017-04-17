class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
        	unordered_map<int, int> mp;
        	for (int j = 0; j < points.size(); ++j) {
        		if (i != j) {
        			int distance = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
        			ans += mp[distance] * 2;
        			++mp[distance];
        		}
        	}
        }
        return ans;
    }
};