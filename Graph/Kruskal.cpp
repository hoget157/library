//Requires: DataStructure/UnionFind, Graph/Template

template <class T>
T kruskal(int n,vector<Edge<T>> &edges){
	T ret = 0;
	sort(edges.begin(),edges.end(),[](const Edge<T> &e1,const Edge<T> &e2){
		return e1.cost < e2.cost;
	});
	UnionFind uf(n);
	for(const Edge<T> &e : edges){
		if(!uf.same(e.from,e.to)){
			ret += e.cost;
			uf.unite(e.from,e.to);
		}
	}
	return ret;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835340