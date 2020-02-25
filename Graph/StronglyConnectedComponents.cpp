//Requires: Graph/Template

template<class T>
struct SCC{
	T g;
	Graph G,rG,nG;
	vector<vector<int>> scc;
	vector<int> cmp,used,vs;

	int operator[](int i) const{ return cmp[i]; }
	
	SCC(T g) : g(g),G(g.size()),rG(g.size()),cmp(g.size(),-1),used(g.size()){
		for(int i = 0;i < g.size();i++){
			for(const auto &e : g[i]){
				G[i].push_back((int)e);
				rG[(int)e].push_back(i);
			}
		}
	}

	void dfs(int v){
		used[v] = true;
		for(int to : G[v]) if(!used[to]) dfs(to);
		vs.push_back(v);
	}

	void rdfs(int v,int cnt){
		scc[cnt].push_back(v);
		cmp[v] = cnt;
		for(int to : rG[v]) if(cmp[to] == -1) rdfs(to,cnt);
	}

	void build(){
		int n = g.size(),cnt = 0;
		for(int i = 0;i < n;i++) if(!used[i]) dfs(i);
		reverse(vs.begin(),vs.end());
		for(int v : vs){
			if(cmp[v] == -1){
				scc.emplace_back();
				rdfs(v,cnt++);
			}
		}
		nG.resize(cnt);
		for(int i = 0;i < n;i++){
			for(const auto &e : g[i]){
				int u = cmp[i],v = cmp[(int)e];
				if(u != v) nG[u].push_back(v);
			}
		}
		for(int i = 0;i < cnt;i++){
			sort(nG[i].begin(),nG[i].end());
			nG[i].erase(unique(nG[i].begin(),nG[i].end()),nG[i].end());
		}
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4206269#1