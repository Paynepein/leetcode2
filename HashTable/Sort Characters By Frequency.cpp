class Solution {
public:
    string frequencySort(string s) {
    	string res;
  		unordered_map<char, int> mp;
  		auto cmp = [](pair<char, int>& a, pair<char, int>& b) -> bool {
  			return a.second < b.second;
  		};
  		priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
  		for (char c : s) ++mp[c];
  		for (auto p : mp) {
  			pq.push(p);
  		}
  		while (!pq.empty()) {
  			res += string(pq.top().second, pq.top().first);
  			pq.pop();
  		}
  		return res;
    }
};