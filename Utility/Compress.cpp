template<class T>
struct Compress{
	vector<T> xs, sorted;
	vector<int> idx;
	Compress(){}
	Compress(const vector<T> &vec, const bool do_build = true){
		add(vec);
		if(do_build) build();
	}
	
	void add(const vector<T> &vec){ xs.insert(xs.end(), vec.begin(), vec.end()); }
	void add(const T &x){ xs.push_back(x); }

	void build(){
		sorted = xs;
		sort(sorted.begin(), sorted.end());
		sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
		idx.resize(xs.size());
		for(int i = 0; i < (int)xs.size(); i++) idx[i] = get(xs[i]);
	}

	const T &operator[](const int i) const{ return sorted[i]; }
	int get(const T &x) const{ return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin(); }
	int size() const{ return sorted.size(); }
};