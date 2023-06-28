template<class T>
struct Edge{
	int from, to, id;
	T cost;
	Edge(int to, T cost) : to(to), cost(cost){}
	Edge(int from, int to, T cost) : from(from), to(to), cost(cost){}
	Edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id){}
	operator int() const noexcept { return to; }
	bool operator<(const Edge &e) const{ return cost < e.cost; }
};

template<class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using Graph = vector<vector<int>>;
template<class T>
using Matrix = vector<vector<T>>;

template<class T, class... Args>
void add_ud_edge(T &G, const int u, const int v, const Args&... args){
	G[u].emplace_back(v, args...);
	G[v].emplace_back(u, args...);
}

#define indg(G, n, m) Graph G(n); rep(i, m){ in(int, u, v); G[u - 1].push_back(v - 1); }
#define inudg(G, n, m) Graph G(n); rep(i, m){ in(int, u, v); add_ud_edge(G, u - 1, v - 1); }
#define inwdg(T, G, n, m) WeightedGraph<T> G(n); rep(i, m){ in(int, u, v); in(T, w); G[u - 1].emplace_back(v - 1, w); }
#define inwudg(T, G, n, m) WeightedGraph<T> G(n); rep(i, m){ in(int, u, v); in(T, w); add_ud_edge(G, u - 1, v - 1, w); }
