//Requires: Graph/Template

template<class T>
void warshallFloyd(Matrix<T> &G, T INFTY = INF){
	int n = G.size();
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(G[i][k] == INFTY || G[k][j] == INFTY) continue;
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835270