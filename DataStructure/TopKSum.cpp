// Requires: DataStructure/ErasableHeap
template<class T>
struct TopKSum{
	ErasableHeap<T, greater<T>> high;
	ErasableHeap<T> low;
	int k;
	T sum;

	TopKSum(const int k) : k(k), sum(0){};
	TopKSum(const int k, const vector<T> &vec) : k(k), sum(0){
		for(const auto &x : vec) add(x);
	}

	void move_low_top(){
		T top = low.pop();
		sum += top;
		high.push(top);
	}
	
	void move_high_bottom(){
		T bottom = high.pop();
		sum -= bottom;
		low.push(bottom);
	}

	void balance(){
		while(high.size() < k && !low.empty()) move_low_top();
		while(high.size() > k) move_high_bottom();
		if(high.empty() || low.empty()) return;
		while(high.top() < low.top()){
			move_low_top();
			move_high_bottom();
		}
	}

	void add(const T &x){
		low.push(x);
		balance();
	}

	void erase(const T &x){
		if(!high.empty() && x >= high.top()){
			high.erase(x);
			sum -= x;
			balance();
		}else low.erase(x);
	}

	void change_k(const int new_k){
		k = new_k;
		balance();
	}

	T get() const{ return sum; }
};