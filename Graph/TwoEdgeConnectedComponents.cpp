//Requires: Graph/Template

template<class T>
struct TwoEdgeConnectedComponents{
	T G;
	Graph nG;
	vector<int> cmp,depth,s;
	vector<vector<int>> tecc;
	stack<int> vs;
	vector<pair<int,int>> bridge;

	int operator[](int i) const{ return cmp[i]; }

	TwoEdgeConnectedComponents(const T &G) : G(G),cmp(G.size()),depth(G.size(),-1),s(G.size()){}

	void dfs(int v,int par,int d){
		depth[v] = d;
		vs.push(v);
		for(const auto &e : G[v]){
			int to = (int)e;
			if(depth[to] == -1){
				dfs(to,v,d + 1);
				s[v] += s[to];
			}else if(to != par && depth[v] > depth[to]) s[to]--,s[v]++;
		}
		if(!s[v]){
			if(par != -1) bridge.push_back(minmax(v,par));
			tecc.emplace_back();
			while(1){
				int u = vs.top(); vs.pop();
				tecc.back().push_back(u);
				cmp[u] = tecc.size() - 1;
				if(u == v) break;
			}
		}
	}

	void build(){
		for(int i = 0;i < G.size();i++) if(depth[i] == -1) dfs(i,-1,0);
		nG.resize(tecc.size());
		for(const auto &e : bridge){
			int x = cmp[e.first],y = cmp[e.second];
			nG[x].push_back(y);
			nG[y].push_back(x);
		}
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4217602#1