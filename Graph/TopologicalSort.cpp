//Requires: Graph/Template

vector<int> topologicalSort(const Graph &G){
	int n = G.size();
	vector<int> inDegree(n),ret;
	queue<int> que;
	for(int i = 0;i < n;i++){
		for(int to : G[i]) inDegree[to]++;
	}
	for(int i = 0;i < n;i++){
		if(!inDegree[i]) que.push(i);
	}
	while(!que.empty()){
		int v = que.front(); que.pop();
		ret.push_back(v);
		for(int to : G[v]){
			inDegree[to]--;
			if(!inDegree[to]) que.push(to);
		}
	}
	return ret;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3997711#1