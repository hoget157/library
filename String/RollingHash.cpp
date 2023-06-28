template<class T>
struct RollingHash{
	using ll = __int128_t;
	const ll mod = (1ll << 61) - 1;
	const ll bases[10] = {10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093};
	
	int n;
	ll base;
	vector<ll> powers;
	vector<vector<ll>> hashes;

	inline ll calc_mod(const ll x) const{
		ll t = (x >> 61) + (x & mod);
		return (t >= mod ? t - mod : t);
	}

	RollingHash(const int n) : n(n), powers(n + 1, 1){
		mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<int> dist(0, 9);
		base = bases[dist(mt)];
		for(int i = 0; i < n; i++) powers[i + 1] = calc_mod(powers[i] * base);
	}

	int add(const string &s){
		vector<ll> a(s.length());
		for(int i = 0; i < (int)s.length(); i++) a[i] = s[i];
		return add(a);
	}

	int add(const vector<T> &a){
		const int m = a.size(), x = hashes.size();
		hashes.emplace_back(m + 1, 0);
		for(int i = 0; i < m; i++) hashes[x][i + 1] = calc_mod(hashes[x][i] * base + a[i]);
		return x;
	}

	inline ll hash(const int x, const int l = 0, int r = -1) const{
		if(r == -1) r = hashes[x].size() - 1;
		return calc_mod(hashes[x][r] - hashes[x][l] * powers[r - l] + mod * mod);
	}
	
	inline bool is_same(const int x, const int lx, const int rx, const int y, const int ly, const int ry) const{
		return hash(x, lx, rx) == hash(y, ly, ry);
	}
};
// https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=7984725#1