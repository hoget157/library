//Requires: Graph/Template

template<class T>
vector<T> dijkstra(const WeightedGraph<T> &G,int source = 0){
	using P = pair<T,int>;
	vector<T> dist(G.size(),INF);
	priority_queue<P,vector<P>,greater<P>> que;
	dist[source] = 0;
	que.emplace(dist[source],source);
	while(!que.empty()){
		P p = que.top();que.pop();
		int v = p.second;
		if(dist[v] < p.first) continue;
		for(const auto &e : G[v]){
			if(dist[e.to] > dist[v] + e.cost){
				dist[e.to] = dist[v] + e.cost;
				que.emplace(dist[e.to],e.to);
			}
		}
	}
	return dist;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3834038