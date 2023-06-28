vector<vector<pair<int, int>>> factorization_table(const int n){
	vector<vector<pair<int, int>>> ret(n + 1);
	for(int i = 2; i <= n; i++){
		if(ret[i].size()) continue;
		for(int j = i; j <= n; j += i) ret[j].emplace_back(i, 1);
		int ipow = i * i;
		while(ipow <= n){
			for(int j = ipow; j <= n; j += ipow) ret[j].back().second++;
			ipow *= i;
		}
	}
	return ret;
}