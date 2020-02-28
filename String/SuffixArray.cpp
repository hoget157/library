struct SuffixArray{
	string s;
	vector<int> sa;

	int operator[](int i) const{ return sa[i]; }

	SuffixArray(const string &t) : s(t),sa(s.size() + 1){
		s += '$';
		int n = s.size();
		iota(sa.begin(),sa.end(),0);
		sort(sa.begin(),sa.end(),[&](int a,int b){ return s[a] < s[b]; });
		vector<int> rnk(s.begin(),s.end()),cnt(n),nxt(n);
		for(int k = 1;k < n;k <<= 1){
			nxt[sa[0]] = 0;
			for(int i = 1;i < n;i++){
				nxt[sa[i]] = (rnk[sa[i - 1]] == rnk[sa[i]]
				&& rnk[(sa[i - 1] + k / 2) % n] == rnk[(sa[i] + k / 2) % n])
				? nxt[sa[i - 1]] : i;
			}
			rnk.swap(nxt);

			iota(cnt.begin(),cnt.end(),0);
			for(int i = 0;i < n;i++){
				int s1 = (sa[i] - k + n) % n;
				nxt[cnt[rnk[s1]]++] = s1;
			}
			sa.swap(nxt);
		}
	}

	inline int lower_bound(const string &t) const{
		return partition_point(sa.begin(),sa.end(),[&](int x){
			return s.compare(x,t.length(),t) < 0;
		}) - sa.begin();
	}

	int upper_bound(string &t) const{
		t.back()++;
		int ret = lower_bound(t);
		t.back()--;
		return ret;
	}

	inline int count(string &t) const{
		return upper_bound(t) - lower_bound(t);
	}
};
//verified:
//https://judge.yosupo.jp/submission/4243
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4214736#1