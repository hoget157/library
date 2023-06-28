template<class T>
struct Components{
	T G;
	vector<int> cmp, used;
	vector<vector<int>> c;

	Components(const T &G) : G(G), cmp(G.size(), -1){ build(); }

	void dfs(const int v){
		cmp[v] = c.size() - 1;
		c.back().push_back(v);
		for(const auto &e : G[v]){
			if(cmp[(int)e] == -1) dfs((int)e);
		}
	}

	void build(){
		for(int i = 0; i < (int)G.size(); i++){
			if(cmp[i] == -1){
				c.emplace_back();
				dfs(i);
			}
		}
	}

	int size() const{ return c.size(); }
	bool is_connected() const{ return size() == 1; }
};