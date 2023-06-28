template<class T>
T nCr(const int n, const int r){
	T ans = 1;
	for(int i = 1; i <= r; i++) ans = ans * (n - r + i) / i;
	return ans;
}
// https://atcoder.jp/contests/arc009/submissions/42833664