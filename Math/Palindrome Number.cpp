class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0 && x < 10) return true;
    	if (x < 0 || x % 10 == 0) return false;
  		int cx = 0;
  		while (cx < x && cx != x / 10) {
  			cx = cx * 10 + x % 10;
  			x /= 10;
  		}
  		if (cx == x || cx == x / 10) return true;
  		return false;
    }
};