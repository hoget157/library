struct QuickFind{
	vector<int> par;
	vector<vector<int>> group;
	QuickFind(int n) : par(n),group(n){
		for(int i = 0;i < n;i++){
			par[i] = i;
			group[i].push_back(i);
		}
	}
	int find(int x){
		return par[x];
	}
	void unite(int x,int y){
		x = par[x],y = par[y];
		if(x == y) return;
		if(group[x].size() < group[y].size()) swap(x,y);
		for(int v : group[y]) par[v] = x;
		group[x].insert(group[x].end(),group[y].begin(),group[y].end());
		group[y].clear();
		par[y] = x;
	}
	bool same(int x,int y){
		return par[x] == par[y];
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4027303#1