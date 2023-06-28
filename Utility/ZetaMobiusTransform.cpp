template<class T>
vector<T> zeta_transform(const int n, const vector<T> &a, bool is_subset){
	vector<T> ret = a;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (1 << n); j++){
			if((j >> i & 1) ^ is_subset) ret[j ^ (1 << i)] += ret[j];
		}
	}
	return ret;
}

template<class T>
vector<T> mobius_transform(const int n, const vector<T> &a, bool is_subset){
	vector<T> ret = a;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (1 << n); j++){
			if((j >> i & 1) ^ is_subset) ret[j ^ (1 << i)] -= ret[j];
		}
	}
	return ret;
}