template<class T>
vector<T> montmort(const int n){
	vector<T> ret(n + 1);
	ret[2] = 1;
	for(int i = 3; i <= n; i++) ret[i] = (ret[i - 1] + ret[i - 2]) * (i - 1);
	return ret;
}
// https://atcoder.jp/contests/arc009/submissions/42833664