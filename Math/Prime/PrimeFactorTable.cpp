vector<vector<int>> prime_factor_table(const int n){
	vector<vector<int>> ret(n + 1);
	for(int i = 2; i <= n; i++){
		if(ret[i].size()) continue;
		for(int j = i; j <= n; j += i) ret[j].push_back(i);
	}
	return ret;
}