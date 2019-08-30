template<class T>
struct EdmondsKarp{
	struct Edge{
		int to,rev;
		T cap;
		Edge(int to,T cap,int rev) : to(to),rev(rev),cap(cap){}
	};

	vector<vector<Edge>> G;

	EdmondsKarp(int n) : G(n){}

	void addEdge(int from,int to,T cap,bool isDirected = true){
		G[from].emplace_back(to,cap,G[to].size());
		G[to].emplace_back(from,isDirected ? 0 : cap,G[from].size() - 1);
	}

	T flow(int s,int t){
		T ret = 0;
		while(1){
			queue<int> que;
			vector<int> prevv(G.size(),-1),preve(G.size(),-1);
			vector<T> aug(G.size(),numeric_limits<T>::max());
			que.push(s);
			while(!que.empty()){
				int v = que.front();que.pop();
				if(v == t) break;
				for(int i = 0;i < G[v].size();i++){
					const auto &e = G[v][i];
					if(prevv[e.to] < 0 && e.cap){
						prevv[e.to] = v;
						preve[e.to] = i;
						aug[e.to] = min(aug[v],e.cap);
						que.push(e.to);
					}
				}
			}
			if(prevv[t] < 0) return ret;
			for(int v = t;v != s;v = prevv[v]){
				G[prevv[v]][preve[v]].cap -= aug[t];
				G[v][G[prevv[v]][preve[v]].rev].cap += aug[t];
			}
			ret += aug[t];
		}
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3839838