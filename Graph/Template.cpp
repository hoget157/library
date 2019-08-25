template<class T>
struct Edge{
	int from,to;
	T cost;
	Edge(int to,T cost) : to(to),cost(cost){}
	Edge(int from,int to,T cost) : from(from),to(to),cost(cost){}
};

template<class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using Graph = vector<vector<int>>;
template<class T>
using Matrix = vector<vector<T>>;