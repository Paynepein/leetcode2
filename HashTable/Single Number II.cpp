ab  c  ab/ab 
00 1/0 01/00
01 1/0 10/01
10 1/0 00/10 

a = ~a&b&c + a&~b&~c
b = ~a&~b&c + ~a&b&~c

class Solution {
public:
    int singleNumber(vector<int>& nums) {
  		int a = 0, b = 0;
  		for (int n : nums) {
  			int t = ~a&b&n | a&~b&~n;
  			b = ~a&~b&n | ~a&b&~n;
  			a = t;
  		}
  		return a | b;
    }
};


k = 3(11) > mask = ~( x1 & x2 )
p = 1;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
  		int x1 = 0, x2 = 0, mask = 0;
  		for (int n : nums) {
  			x2 ^= x1 & n;
  			x1 ^= n;
  			mask = ~(x1 & x2);
  			x2 &= mask;
  			x1 &= mask;
  		}
  		return x1;
    }
};