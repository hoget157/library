// s = -1: any start node, s = -2: return to start node
template<class T>
T tsp(const Matrix<T> &d, const int s, const T INFTY = INF){
	const int n = d.size();
	vector<vector<T>> dp(1 << n, vector<T>(n, INFTY));
	if(s == -1) for(int i = 0; i < n; i++) dp[1 << i][i] = 0;
	else if(s == -2) dp[0][0] = 0;
	else dp[1 << s][s] = 0;
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(j == k || ((i >> k) & 1)) continue;
				chmin(dp[i | (1 << k)][k], dp[i][j] + d[j][k]);
			}
		}
	}
	dbg(dp);
	if(s == -1) return min(dp[(1 << n) - 1]);
	else return dp[(1 << n) - 1][max(T(0), s)];
}
// https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=7970933#1