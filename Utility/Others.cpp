template<class T>
bool is_same_vector(const vector<T> &v1, const vector<T> &v2){
	if(v1.size() != v2.size()) return false;
	for(int i = 0; i < (int)v1.size(); i++){
		if(v1[i] != v2[i]) return false;
	}
	return true;
}

template<class T>
bool is_same_vector(const int n, const T a1[], const T a2[]){
	return is_same_vector(vector<T>(a1, a1 + n), vector<T>(a2, a2 + n));
}

template<class T>
bool is_same_set(vector<T> v1, vector<T> v2){
	if(v1.size() != v2.size()) return false;
	if(v1.empty()) return true;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	return is_same_vector(v1, v2);
}

template<class T>
bool is_same_set(const int n, const T a1[], const T a2[]){
	return is_same_set(vector<T>(a1, a1 + n), vector<T>(a2, a2 + n));
}
