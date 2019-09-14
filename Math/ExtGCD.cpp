template<class T>
T extgcd(T a,T b,T &x,T &y){
	T d = a;x = 1;y = 0;
	if(b != 0){
		d = extgcd(b,a % b,y,x);
		y -= (a / b) * x;
	}
	return d;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3868753