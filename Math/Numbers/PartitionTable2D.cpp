template<class T>
vector<vector<T>> partitionTable2D(int n,int k){
	vector<vector<T>> dp(n + 1,vector<T>(k + 1));
	dp[0][0] = 1;
	for(int i = 0;i <= n;i++){
		for(int j = 1;j <= k;j++){
			dp[i][j] = dp[i][j - 1] + (i >= j ? dp[i - j][j] : T(0));
		}
	}
	return dp;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3868747