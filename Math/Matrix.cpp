template<class T>
struct Matrix{
	vector<vector<T>> A;
	Matrix(int n) : A(n,vector<T>(n,T(0))){}
	Matrix(int n,int m) : A(n,vector<T>(m,T(0))){}

	int size() const{ return A.size(); }
	vector<T> &operator[](const int k){ return A[k]; }
	const vector<T> &operator[](const int k) const{ return A[k]; }
	Matrix operator*(const T &x) const{ Matrix(*this) *= x; }
	Matrix operator*(const Matrix &B) const{ Matrix(*this) *= B; }
	
	Matrix &operator*=(const T &x){
		for(int i = 0;i < A.size();i++){
			for(int j = 0;j < A[0].size();j++) A[i][j] *= x;
		}
		return *this;
	}

	Matrix &operator*=(const Matrix &B) {
		assert(A[0].size() == B.size());
		vector<vector<T>> C(A.size(),vector<T>(B[0].size(),T(0)));
		for(int i = 0;i < A.size();i++){
			for(int k = 0;k < B.size();k++){
				for(int j = 0;j < B[0].size();j++) C[i][j] += A[i][k] * B[k][j];
			}
		}
		A.swap(C);
		return *this;
	}

	vector<T> operator*(const vector<T> &v) const{
		assert(A[0].size() == v.size());
		vector<T> ret(A.size());
		for(int i = 0;i < A.size();i++){
			for(int j = 0;j < A[0].size();j++) ret[i] += A[i][j] * v[j];
		}
		return ret;
	}

	Matrix pow(long long x) const{
		assert(A.size() == A[0].size());
		Matrix ret = E(A.size()),tmp = *this;
		for(;x;tmp *= tmp,x >>= 1){
			if(x & 1) ret *= tmp;
		}
		return ret;
	}

	static Matrix E(int n){
		Matrix ret(n);
		for(int i = 0;i < n;i++) ret[i][i] = T(1);
		return ret;
	}
};
//!!!!!!unverified!!!!!!