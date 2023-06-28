template<class T>
struct BellmanFord{
	WeightedGraph<T> G;
	int n;
	vector<T> dist;
	vector<int> prv;
	T INFTY;
	
	BellmanFord(const WeightedGraph<T> &G, const T INFTY = INF) : 
	G(G), n(G.size()), dist(n, INFTY), prv(n), INFTY(INFTY){}

	bool run(const int s, const bool find_all_neg_cycle, const int t = -1){
		if(find_all_neg_cycle) fill(dist.begin(), dist.end(), 0);
		dist[s] = 0;
		for(int i = 0; i < 2 * n - 1; i++){
			bool update = false;
			for(int v = 0; v < n; v++){
				if(dist[v] == INFTY) continue;
				for(const auto &e : G[v]){
					if(dist[e.to] > dist[v] + e.cost){
						if(t != -1 && i >= n - 1){
							if(e.to == t) return true;
							dist[e.to] = -INFTY;
						}else{
							dist[e.to] = dist[v] + e.cost;
							prv[e.to] = v;
							update = true;
						}
					}
				}
			}
			if(!update) break;
			if(t == -1 && i >= n - 1) return true;
		}
		return false;
	}

	vector<int> traceback(const int s, const int t) const{
		vector<int> ret;
		int v = t;
		while(v != s){
			ret.push_back(v);
			v = prv[v];
		}
		ret.push_back(s);
		return ret;
	}
};
// https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=7982559#1