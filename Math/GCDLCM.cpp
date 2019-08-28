template<class T>
T gcd(T a,T b){
	return b ? gcd(b,a % b) : a;
}

template<class T>
T lcm(T a,T b){
	return a / gcd(a,b) * b;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835971