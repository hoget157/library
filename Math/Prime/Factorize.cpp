vector<pair<int, int>> factorize(const int x){
	vector<pair<int, int>> factors;
	int _x = x;
	for(int i = 2; i * i <= x; i++){
		if(_x % i) continue;
		int e = 0;
		while(_x % i == 0){
			e++;
			_x /= i;
		}
		factors.emplace_back(i, e);
	}
	if(_x != 1) factors.emplace_back(_x, 1);
	return factors;
}
 
vector<int> factorize_simple(const int x){
	vector<pair<int, int>> tmp = factorize(x);
	vector<int> ret;
	for(auto v : tmp) ret.push_back(v.first);
	return ret;
}

// verified: https://atcoder.jp/contests/abc272/submissions/41784849