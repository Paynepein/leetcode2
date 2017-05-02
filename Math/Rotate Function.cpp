class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int res = 0, F = 0, sum = 0;
        for (int i = 0; i < A.size(); ++i) {
        	F += i * A[i];
        	sum += A[i];
        }
        res = F;
        for (int i = A.size()-1; i > 0; --i) {
        	F = F + sum - A.size()*A[i];
        	res = max(res, F);
        }
        return res;
    }
};