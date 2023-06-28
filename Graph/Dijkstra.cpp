//Requires: Graph/Template

template<class T>
vector<T> dijkstra(const WeightedGraph<T> &G, const vector<int> &sources, const T INFTY = INF){
	if(sources.empty()) return vector<T>(G.size(), INFTY);
	using pti = pair<T, int>;
	vector<T> dist(G.size(), INFTY);
	priority_queue<pti, vector<pti>, greater<pti>> que;
	for(int s : sources){
		dist[s] = T(0);
		que.emplace(dist[s], s);
	}
	while(!que.empty()){
		auto [cost, v] = que.top(); que.pop();
		if(dist[v] < cost) continue;
		for(const auto &e : G[v]){
			if(dist[e.to] > dist[v] + e.cost){
				dist[e.to] = dist[v] + e.cost;
				que.emplace(dist[e.to], e.to);
			}
		}
	}
	return dist;
}

template<class T>
vector<T> dijkstra(const WeightedGraph<T> &G, const int source = 0, const T INFTY = INF){
	return dijkstra(G, vector<int>{source}, INFTY);
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3834038