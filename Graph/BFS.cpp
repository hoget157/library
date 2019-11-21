//Requires: Graph/Template

template<class T = int>
vector<T> BFS(const Graph &G,int source = 0){
	vector<T> dist(G.size(),-1);
	queue<int> que;
	dist[source] = 0;
	que.push(source);
	for(T d = 0;;d++){
		int siz = que.size();
		if(siz == 0) break;
		for(int i = 0;i < siz;i++){
			int v = que.front();que.pop();
			for(int to : G[v]){
				if(dist[to] == -1){
					dist[to] = d + 1;
					que.push(to);
				}
			}
		}
	}
	return dist;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3997697#1