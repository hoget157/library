template<class T>
struct CumulativeSum{
	vector<T> csum;
	CumulativeSum(const int n): csum(n + 1){}
	CumulativeSum(const vector<T> &a) : csum(a.size() + 1){
		for(int i = 0; i < (int)a.size(); i++) csum[i + 1] = csum[i] + a[i];
	}

	void update(const int i, const T &x){ csum[i + 1] = csum[i] + x; }
	T get(const int r = csum.size()) const{ return csum[r]; }
	T get(const int l, const int r) const{ return csum[r] - csum[l]; }
};

template<class T>
struct CumulativeSum2D{
	vector<vector<T>> csum;
	CumulativeSum2D(const int n, const int m) : csum(n + 1, vector<T>(m + 1)){}
	CumulativeSum2D(const vector<vector<T>> &a) : csum(a.size() + 1, vector<T>(a[0].size() + 1)){
		for(int i = 0; i < (int)a.size(); i++){
			for(int j = 0; j < (int)a[0].size(); j++){
				update(i, j, a[i][j]);
			}
		}
	}

	void update(const int i, const int j, const T &x){
		csum[i + 1][j + 1] = x + csum[i + 1][j] + csum[i][j + 1] - csum[i][j];
	}

	T get(const int x, const int yl, const int yr) const{ return get(x, x + 1, yl, yr); }
	T get(const int xl, const int xr, const int yl, const int yr) const{
		return csum[xr][yr] - csum[xl][yr] - csum[xr][yl] - csum[xl][yl];
	}
};
