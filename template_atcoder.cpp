#pragma region header
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define isIn(x, y, h, w) ((x) >= 0 && (x) < (h) && (y) >= 0 && (y) < (w))
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(auto i = (n) - 1; i >= 0; i--)
#define repi(i, n1, n2) for(auto i = (n1); i < (n2); i++)
#define rrepi(i, n1, n2) for(auto i = (n2) - 1; i >= (n1); i--)
#define rep2(i, j, n) rep(i, n) repi(j, i + 1, n)
#define min_equal(v, x) lower_bound(all(v), (x)) - (v).begin()
#define min_over(v, x) upper_bound(all(v), (x)) - (v).begin()
#define max_equal(v, x) upper_bound(all(v), (x)) - (v).begin() - 1
#define max_under(v, x) lower_bound(all(v), (x)) - (v).begin() - 1

template<class T, class U> static inline vector<U> makevec(const T &n, const U &u){ return vector<U>(n, u); }
template<class T, class... Args> static inline auto makevec(const T &n, const Args&... args){ return vector<decltype(makevec(args...))>(n, makevec(args...)); }

#define in(T, ...) T __VA_ARGS__; input(__VA_ARGS__)
#define inrows(n, ...) rep(i, n) inrow(__VA_ARGS__)
#define invec(T, n, ...) vector<T> __VA_ARGS__; inputvec(n, __VA_ARGS__);
#define invec2(T, n, m, x) vector<vector<T>> x(n, vector<T>(m)); input(x)
template<class... T> inline void input(T&... x){ (cin >> ... >> x); }
template<class T> inline void inputvec(const T &n){ (void)n; }
template<class T, class Head, class... Tail> inline void inputvec(const T &n, Head &v, Tail&... tail){ v.resize(n); cin >> v; inputvec(n, tail...); }
inline void inrow(){}
template<class Head, class... Tail> inline void inrow(Head &x, Tail&... tail){ in(typename Head::value_type, y); x.push_back(y); inrow(tail...); }
template<class T> istream &operator>>(istream &is, vector<T> &x){ for(auto &&v : x) is >> v; return is; }

#ifdef DEBUG
#define dbg(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__); cout << flush
#else
#define dbg(...) (static_cast<void>(0))
#endif
const string DELIMITER[] = 
#ifdef DEBUG 
	{",", "(", ")", "[", "]"};
#else
	{" ", "", "", "", ""};
#endif
ostream &operator<<(ostream &os, __int128_t x){
	if(x < 0) x *= -1, os << '-';
	vector<int> v;
	while(x) v.push_back(x % 10), x /= 10;
	if(!v.size()) return os << 0;
	for(int i = (int)v.size() - 1; i >= 0; i--) os << v[i];
	return os;
}
template<auto T> ostream &operator<<(ostream &os, const atcoder::static_modint<T> &x){ return os << x.val(); }
template<auto T> ostream &operator<<(ostream &os, const atcoder::dynamic_modint<T> &x){ return os << x.val(); }
template<class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){ return os << DELIMITER[1] << p.first << DELIMITER[0] << p.second << DELIMITER[2]; }
template<typename T, typename U = typename T::iterator, enable_if_t<!is_same_v<T, string> && !is_same_v<T, wstring>, nullptr_t> = nullptr>
ostream &operator<<(ostream &os, const T &c){
	for(auto it = c.begin(); it != c.end(); it++) os << DELIMITER[(it == c.begin()) ? 3 : 0] << *it;
	return os << DELIMITER[4];
}
template<class T> inline void prend(const T &a){ cout << a << '\n'; exit(0); }
template<class T> inline void print(const T &a){ cout << a << '\n'; }
template<class Head, class... Tail> inline void print(const Head &a, const Tail&... b){ cout << a << ' '; print(b...); }
inline void prec(const int d){ cout << fixed << setprecision(d); }

const vector<vector<string>> YN_string = {{"Yes", "No"}, {"YES", "NO"}, {"Takahashi", "Aoki"}, {"Alice", "Bob"}, {"Possible", "Impossible"}};
enum class YesNo{ Yes, YES, taka, alice, poss };

inline void i0(){}
template<class T, enable_if_t<is_integral_v<T>, nullptr_t> = nullptr, class... Tail> inline void i0(T &x, Tail&... tail){ x--; i0(tail...); }
template<class T, class... Tail> inline void i0(vector<T> &v, Tail&... tail){ for(auto &&x : v) i0(x); i0(tail...); }

template<class T> inline T div_floor(T a, T b){ if(b < 0) a = -a, b = -b; return a >= 0 ? a / b : (a + 1) / b - 1; }
template<class T> inline T div_ceil(T a, T b){ if(b < 0) a = -a, b = -b; return a <= 0 ? a / b : (a - 1) / b + 1; }
template<class T> inline T div_less(T a, T b){ return div_floor(a, b) - !(a % b); }
template<class T> inline T div_greater(T a, T b){ return div_ceil(a, b) + !(a % b); }

template<class T> inline void sort(vector<T> &v){ sort(v.begin(), v.end()); }
template<class T> inline void rsort(vector<T> &v){ sort(v.rbegin(), v.rend()); }
template<class T> inline void unique(vector<T> &v){ sort(v); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline auto min(const T &a){ return *min_element(a.begin(), a.end()); }
template<class T> inline auto max(const T &a){ return *max_element(a.begin(), a.end()); }
template<class T> inline bool chmin(T &a, const T &b){ return a > b ? a = b, true : false; }
template<class T> inline bool chmax(T &a, const T &b){ return a < b ? a = b, true : false; }
template<class T> inline typename T::value_type mex(const T &st){ for(auto i = typename T::value_type(0); ; i++) if(!st.count(i)) return i; }

using ld = long double;
using ll = long long;
using l128 = __int128;
template<class T> using P = pair<T, T>;
template<class T> using tup3 = tuple<T, T, T>;
template<class T> using heap = priority_queue<T, vector<T>, greater<T>>;
template<class T> using vec2 = vector<vector<T>>;
template<class T> using vec3 = vector<vec2<T>>;
template<class T> using uset = unordered_set<T>;
template<class T, class U> using umap = unordered_map<T, U>;

struct FastIO{ FastIO(){ cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); prec(10); } } fastio__;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<class T> using tree = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#pragma endregion header

#define int long long
const int inf = 2e9;
const int INF = 2e18;
const double EPS = 1e-9;
const int MOD = 998244353;
using pi = pair<int, int>;
using ipi = pair<int, pair<int, int>>;
using pii = pair<pair<int, int>, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vector<int>>;
using mint = atcoder::modint1000000007;
// using mint = atcoder::modint998244353;
// using mint = atcoder::modint;
using vm = vector<mint>;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
#define YN YesNo::Yes
inline void Yes(bool end = false){ print(YN_string[(int)YN][0]); if(end) exit(0); }
inline void No(bool end = false){ print(YN_string[(int)YN][1]); if(end) exit(0); }
inline void isYes(bool x, bool end = false){ print(YN_string[(int)YN][!x]); if(end) exit(0); }

signed main(){
	in(int, n);
	in(string, x);
	
}