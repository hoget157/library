template<class T>
Graph deweight(const WeightedGraph<T> &G){
	const int n = G.size();
	Graph ret(n);
	for(int i = 0; i < n; i++){
		for(const auto &e : G[i]) ret[i].push_back(e.to);
	}
	return ret;
}

template<class T>
WeightedGraph<T> enweight(const Graph &G){
	const int n = G.size();
	WeightedGraph<T> ret(n);
	for(int i = 0; i < n; i++){
		for(const auto &to : G[i]) ret[i].emplace_back(to, T(1));
	}
	return ret;
}

template<class T>
Matrix<T> to_matrix(const WeightedGraph<T> &G, const T INFTY = INF){
	const int n = G.size();
	Matrix<T> ret(n, vector<T>(n));
	for(int i = 0; i < n; i++){
		for(const auto &e : G[i]) ret[i][e.to] += e.cost;
	}
	return ret;
}

template<class T>
WeightedGraph<T> to_weighted_graph(const Matrix<T> &G){
	const int n = G.size();
	WeightedGraph<T> ret(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			ret[i].emplace_back(j, G[i][j]);
		}
	}
	return ret;
}