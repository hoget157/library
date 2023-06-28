template<class T>
struct DFSTree{
	T tree;
	vector<bool> visited;
	DFSTree(T G) : tree(G.size()), visited(G.size()){ dfs(G, 0); }

	void dfs(const T &G, int v){
		visited[v] = true;
		for(const auto &e : G[v]){
			int to = (int)e;
			if(!visited[to]){
				tree[v].push_back(to);
				tree[to].push_back(v);
				dfs(G, to);
			}
		}
	}
};

// verified: https://atcoder.jp/contests/abc244/submissions/41507063