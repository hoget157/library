template<class Q>
struct Mo{
	int n, w;
	vector<Q> qs;
	Mo(int n, int q) : n(n), w(max((int)1, (int)(n / sqrt(2.0 / 3.0 * q)))){}
	
	void add_query(const Q &query){
		qs.push_back(query);
	}

	template<class FAL, class FAR, class FDL, class FDR, class FS>
	void run(const FAL &add_left, const FAR &add_right, const FDL &delete_left, const FDR &delete_right, const FS &sol){
		vector<int> ord(qs.size());
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [&](const int a, const int b){
			const int ab = qs[a].l / w, bb = qs[b].l / w;
			if(ab != bb) return ab < bb;
			return (ab & 1) ? qs[a].r > qs[b].r : qs[a].r < qs[b].r;
		});
		int l = 0, r = 0;
		for(auto i : ord){
			while(l > qs[i].l) add_left(--l);
			while(r < qs[i].r) add_right(r++);
			while(l < qs[i].l) delete_left(l++);
			while(r > qs[i].r) delete_right(--r);
			sol(i);
		}
	}

	template<class FA, class FD, class FS>
	void run(const FA &add, const FD &del, const FS &sol){
		run(add, add, del, del, sol);
	}
};

// verified: https://atcoder.jp/contests/abc293/submissions/41449297
