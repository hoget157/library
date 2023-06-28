template<class T, class F>
T bsearch(T ok, T ng, const F &check, const int max_loop = -1){
	for(int i = 0; (max_loop == -1) ? (abs(ok - ng) > 1) : (i < max_loop); i++){
		T mid = (ok + ng) / 2;
		(check(mid) ? ok : ng) = mid;
	}
	return ok;
}

// verified: https://atcoder.jp/contests/abc229/submissions/41486168
