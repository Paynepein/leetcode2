class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  		int s1 = (C - A) * (D - B), s2 = (G - E) * (H - F);
  		if (E >= C || G <= A || F >= D || H <= B) {
  			return s1 + s2;
  		}
  		int s3 = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
  		return s1 + s2 - s3;
    }
};