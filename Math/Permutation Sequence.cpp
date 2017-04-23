class Solution {
public:
    string getPermutation(int n, int k) {
  		int fact = 1;
  		string res;
  		vector<int> nums(n, 0);
  		for (int i = 1; i <= n; ++i) {
  			fact *= i;
  			nums[i-1] = i;
  		}
  		--k;
  		for (int i = 0; i < n; ++i) {
  			fact /= n-i;
  			int index = k / fact;
  			res += nums[index] + '0';
  			nums.erase(nums.begin()+index);
  			k -= fact * index;
  		}
  		return res;
    }
};