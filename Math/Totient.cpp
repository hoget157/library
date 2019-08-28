int totient(int n){
	int ret = n,n_ = n;
	for(int i = 2;i * i <= n;i++){
		if(n_ % i == 0){
			while(n_ % i == 0) n_ /= i;
			ret -= ret / i;
		}
	}
	if(n_ > 1) ret -= ret / n_;
	return ret; 
}
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835962