inline void rotate(int &x, int &y, const int h, const int w){
	int tmp = x;
	x = y;
	y = h - tmp - 1;
	(void)w;
}

template<class T>
inline void rotate(int &n, int &m, vector<vector<T>> &a){
	vector<vector<T>> ret(m, vector<T>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) ret[j][n - i - 1] = a[i][j];
	}
	a = ret;
	swap(n, m);
}