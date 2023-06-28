vector<int> totientTable(int n){
	vector<int> ret(n + 1);
	for(int i = 0;i <= n;i++) ret[i] = i;
	for(int i = 2;i <= n;i++){
		if(ret[i] != i) continue;
		for(int j = i;j <= n;j += i) ret[j] -= ret[j] / i;
	}
	return ret;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835967