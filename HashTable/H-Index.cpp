class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int h = citations.size();
  		vector<int> bucket(h+1, 0);
  		for (int n : citations) {
  			if (n >= h) ++bucket[h];
  			else ++bucket[n];
  		}
  		int sum = 0;
  		for (int i = h; i > 0; --i) {
  			sum += bucket[i];
  			if (sum >= i) return i;
  		}
  		return 0;
    }
};