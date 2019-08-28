//Requires: Graph/Template

template<class T>
void warshallFloyd(Matrix<T> &G){
	for(int k = 0;k < G.size();k++){
		for(int i = 0;i < G.size();i++){
			for(int j = 0;j < G.size();j++){
				if(G[i][k] == INF || G[k][j] == INF) continue;
				G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
			}
		}
	}
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835270