vector<int> get_xor_basis_idx(const vector<int> &a){
	vector<int> basis, idx;
	for(int i = 0; i < (int)a.size(); i++){
		int x = a[i];
		for(const auto &b : basis) chmin(x, x ^ b);
		if(x){
			basis.push_back(x);
			idx.push_back(i);
		}
	}
	return idx;
}
// https://atcoder.jp/contests/zone2021/submissions/42271227

vector<int> get_xor_basis(const vector<int> &a){
	vector<int> basis;
	for(int i = 0; i < (int)a.size(); i++){
		int x = a[i];
		for(const auto &b : basis) chmin(x, x ^ b);
		for(auto &&b : basis) chmin(b, b ^ x);
		if(x) basis.push_back(x);
	}
	sort(basis.begin(), basis.end());
	return basis;
}
// https://atcoder.jp/contests/abc283/submissions/42834115