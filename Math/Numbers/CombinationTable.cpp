template<class T>
struct CombinationTable{
	vector<vector<T>> nCr;
	CombinationTable(const int n) : nCr(n + 1, vector<T>(n + 1)){
		for(int i = 0; i <= n; i++) nCr[i][0] = nCr[i][i] = T(1);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= i - 1; j++){
				nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
			}
		}
	}
};

// verified: https://atcoder.jp/contests/abc281/submissions/41486010
