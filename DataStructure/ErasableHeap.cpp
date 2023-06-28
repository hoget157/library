template<class T, class U = less<T>>
struct ErasableHeap{
	priority_queue<T, vector<T>, U> que, erased;
	ErasableHeap(){}
	ErasableHeap(const vector<T> &v){ for(const auto &x : v) push(x); }
	void push(const T &x){ que.push(x); }
	void erase(const T &x){ erased.push(x); }
	int size() const{ return que.size() - erased.size(); }
	bool empty() const{ return !size(); }

	void normalize(){
		while(!erased.empty() && que.top() == erased.top()){
			que.pop();
			erased.pop();
		}	
	}

	T top(){
		normalize();
		return que.top();
	}

	T pop(){
		T ret = top();
		que.pop();
		return ret;
	}
};