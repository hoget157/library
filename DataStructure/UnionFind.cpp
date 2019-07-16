struct UnionFind{
	vector<int> rnk,par;

	UnionFind(int sz) : rnk(sz,0),par(sz){
		for(int i = 0;i < sz;i++) par[i] = i;
	}

	int find(int x){
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rnk[x] < rnk[y]) swap(x,y);
		par[y] = x;
		if(rnk[x] == rnk[y]) rnk[x]++;
	}
	
	bool same(int x,int y){
		return (find(x) == find(y));
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3755220