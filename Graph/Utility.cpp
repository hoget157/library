template<class T>
vector<int> calc_indeg(const T &G){
	vector<int> in(G.size());
	for(int i = 0; i < (int)G.size(); i++){
		for(const auto &e : G[i]) in[(int)e]++;
	}
	return in;
}

// verified: https://atcoder.jp/contests/abc257/submissions/41486866