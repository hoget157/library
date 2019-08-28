bool isPrime(int x){
	if(x == 2) return true;
	if(x % 2 == 0 || x <= 1) return false;
	for(int i = 3;i * i <= x;i += 2){
		if(x % i == 0) return false;
	}
	return true;
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835518