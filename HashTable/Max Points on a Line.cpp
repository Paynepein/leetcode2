/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
  		if (points.size() <= 2) return points.size();
  		int res = 0;
  		for (int i = 0; i < points.size(); ++i) {
  			unordered_map<int, unordered_map<int, int>> mp;
  			int ans = 0, overlap = 0;
  			for (int j = i+1; j < points.size(); ++j) {
  				int x = points[j].x - points[i].x;
  				int y = points[j].y - points[i].y;
  				if (x == 0 && y == 0) {
  					++overlap;
  					continue;
  				}
  				int r = gcd(x, y);
  				if (r != 0) {
  					x /= r;
  					y /= r;
  				}
  				if (mp.find(x) != mp.end()) {
  					++mp[x][y];
  				} else {
  					unordered_map<int, int> m;
  					m[y] = 1;
  					mp[x] = m;
  				}
  				ans = max(ans, mp[x][y]);
  			}
  			res = max(res, ans + overlap + 1);
  		}
  		return res;
    }

    int gcd(int a, int b) {
    	if (b == 0) return a;
    	return gcd(b, a%b);
    }
};