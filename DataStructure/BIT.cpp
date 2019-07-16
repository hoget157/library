template<class T>
struct BIT{
	vector<T> dat;

	BIT(int sz) : dat(sz,0){}

	void add(int i,T x){
		for(;i < dat.size();i += i & -i) dat[i] += x;
	}

	T sum(T i){
		T ret = 0;
		for(;i;i -= i & -i) ret += dat[i];
		return ret;
	}
};
//verified : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3755228