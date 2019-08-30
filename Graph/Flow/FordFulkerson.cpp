template<class T>
struct FordFulkerson{
	struct Edge{
		int to,rev;
		T cap;
		Edge(int to,T cap,int rev) : to(to),rev(rev),cap(cap){}
	};

	vector<vector<Edge>> G;
	vector<bool> used;

	FordFulkerson(int n) : G(n),used(n){}

	void addEdge(int from,int to,T cap,bool isDirected = true){
		G[from].emplace_back(to,cap,G[to].size());
		G[to].emplace_back(from,isDirected ? 0 : cap,G[from].size() - 1);
	}

	T dfs(int v,int t,T f){
		if(v == t) return f;
		used[v] = true;
		for(auto &e : G[v]){
			if(!used[e.to] && e.cap){
				T d = dfs(e.to,t,min(f,e.cap));
				if(d){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	T flow(int s,int t){
		T ret = 0;
		while(1){
			fill(used.begin(),used.end(),0);
			T f = dfs(s,t,numeric_limits<T>::max());
			if(!f) return ret;
			ret += f;
		}
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3839814