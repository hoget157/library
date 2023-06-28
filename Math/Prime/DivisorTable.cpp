vector<vector<int>> divisor_table(const int n){
	vector<vector<int>> ret(n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i) ret[j].push_back(i);
	}
	return ret;
}