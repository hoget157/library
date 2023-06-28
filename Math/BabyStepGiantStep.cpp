// returns min k >= 0 s.t. f^k(x) = y, else -1
template<class T, class U, class F, class FM>
U bsgs(const T &x, const T &y, const U &n, const U &m, const F &f, const FM &fm){
	unordered_map<T, U> table;
	// baby step
	T fy = y;
	for(U i = 1; i <= m; i++) table[fy = f(fy)] = i;
	// giant step
	T fmx = x;
	for(U i = 1; i <= (n + m - 1) / m; i++){
		if(table.count(fmx = fm(fmx))) return i * m - table[fmx];
	}
	return -1;
}

template<class T, class U>
T bsgs(const T &x, const T &y, const U &p){
	U m = sqrt(p);
	auto f = [&](const T &a){ return (x * a) % p; };
	T xpow = 1;
	for(U i = 0; i < m; i++) (xpow *= x) %= p;
	auto fm = [&](const T &a){ return (xpow * a) % p; };
	return bsgs(T(1), y, p, m, f, fm);
}
// https://atcoder.jp/contests/abc270/submissions/42071844

// find min 0<=k<n s.t. x^k.s=t
// f: X x S -> S; left action
// op: X x X -> X; monoid operation
template<class S, class X, class T, class FA, class FOP>
T bsgs(const S &s, const S &t, const X &x, const T &n, const FA &f, const FOP &op){
	T m = sqrt(n) + 1;
	unordered_set<S> table;
	// baby step
	S xt = t;
	for(T i = 1; i <= m; i++) table.insert(xt = f(x, xt));
	// calc x^m=x*x^(m-1)
	T m_ = m - 1;
	X xm = x, xpow = x;
	for(; m_; xpow = op(xpow, xpow), m_ >>= 1){
		if(m_ & 1) xm = op(xpow, xm);
	}
	// giant step
	int attempt = 0;
	S xms = s;
	for(T i = 1; i <= (n + m - 1) / m; i++){
		S xms_nxt = f(xm, xms);
		if(table.count(xms_nxt)){
			for(T j = (i - 1) * m; j < i * m; j++){
				if(xms == t) return j;
				xms = f(x, xms);
			}
			if(++attempt >= 2) break;
		}
		xms = xms_nxt;
	}
	return -1;
}

template<class S, class T>
T mod_log(const S &x, const S &y, const T &p){
	auto f = [&](const S &a, const S &b){ return (a * b) % p; };
	return bsgs(S(1 % p), y, x, p, f, f);
}
// https://judge.yosupo.jp/submission/143843