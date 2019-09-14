template<class T>
vector<T> partitionTable1D(int n){
	vector<T> ret(n + 1);
	ret[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;;j++){
			int p1 = j * (3 * j - 1) / 2,p2 = j * (3 * j + 1) / 2;
			if(i - p1 < 0) break;
			else ret[i] += ret[i - p1] * T(((j % 2) ? 1 : -1));
			if(i - p2 < 0) break;
			else ret[i] += ret[i - p2] * T(((j % 2) ? 1 : -1));
		}
	}
	return ret;
}
//!!!!!!unverified!!!!!!