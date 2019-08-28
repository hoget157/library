struct PrimeTable{
	vector<int> primeList;
	vector<bool> isPrime;
	PrimeTable(int n) : isPrime(n + 1,true){
		isPrime[0] = false;
		isPrime[1] = false;
		for(int i = 4;i <= n;i += 2) isPrime[i] = false;
		for(int i = 3;i * i <= n;i += 2){
			if(!isPrime[i]) continue;
			for(int j = i * 2;j <= n;j += i) isPrime[j] = false;
		}
		for(int i = 0;i <= n;i++){
			if(isPrime[i]) primeList.push_back(i);
		}
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3835575