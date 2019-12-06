const long long baseNum = 3,bases[] = {10007,10009,10037};

template<long long mod = 1000000007>
struct RollingHash{
	using ll = long long;
	vector<ll> hashes[baseNum],powers[baseNum];
	RollingHash(string &s){
		int n = s.length();
		for(int i = 0;i < baseNum;i++){
			hashes[i].resize(n + 1,0);
			powers[i].resize(n + 1,1);
			for(int j = 0;j < n;j++){
				powers[i][j + 1] = powers[i][j] * bases[i] % mod;
				hashes[i][j + 1] = (hashes[i][j] * bases[i] + s[j]) % mod;
			}
		}
	}
	ll getHash(int l,int r,int b){
		return (hashes[b][r] - hashes[b][l] * powers[b][r - l] % mod + mod) % mod;
	}
	vector<ll> getHash(int l = 0,int r = -1){
		if(r == -1) r = hashes[0].size() - 1;
		vector<ll> ret(baseNum);
		for(int i = 0;i < baseNum;i++){
			ret[i] = getHash(l,r,i);
		}
		return ret;
	}
	static bool sameString(vector<ll> v1,vector<ll> v2){
		assert(v1.size() == v2.size());
		for(int i = 0;i < v1.size();i++){
			if(v1[i] != v2[i]) return false;
		}
		return true;
	}
};
//verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3985050