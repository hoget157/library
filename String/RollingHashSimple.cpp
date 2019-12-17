const long long bases[] = {10007,10009/*,10037*/};

template<long long mod = 1000000007>
struct RollingHashSimple{
	using ll = long long;
	vector<ll> hashes[2],powers[2];
	RollingHashSimple(const string &s){
		int n = s.length();
		for(int i = 0;i < 2;i++){
			hashes[i].resize(n + 1,0);
			powers[i].resize(n + 1,1);
			for(int j = 0;j < n;j++){
				powers[i][j + 1] = powers[i][j] * bases[i] % mod;
				hashes[i][j + 1] = (hashes[i][j] * bases[i] + s[j]) % mod;
			}
		}
	}
	inline ll hash(int l,int r,int b) const{
		return (hashes[b][r] - hashes[b][l] * powers[b][r - l] % mod + mod) % mod;
	}
	ll hash(int l = 0,int r = -1) const{
		if(r == -1) r = hashes[0].size() - 1;
		return hash(l,r,0) * mod + hash(l,r,1);
	}
	inline bool isSame(int a,int b,int c,int d) const{
		return hash(a,b) == hash(c,d);
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4054477#1