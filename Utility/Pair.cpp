template<class T1, class T2> pair<T1, T2> operator-(const pair<T1, T2> &p){ return make_pair(-p.first, -p.second); }
template<class T1, class T2> pair<T1, T2> operator+(const pair<T1, T2> &p1, const pair<T1, T2> &p2){ return make_pair(p1.first + p2.first, p1.second + p2.second); }
template<class T1, class T2> pair<T1, T2> operator-(const pair<T1, T2> &p1, const pair<T1, T2> &p2){ return make_pair(p1.first - p2.first, p1.second - p2.second); }
template<class T1, class T2, class U> pair<T1, T2> operator*(const pair<T1, T2> &p, const U &x){ return make_pair(p.first * x, p.second * x); }
template<class T1, class T2, class U> pair<T1, T2> operator/(const pair<T1, T2> &p, const U &x){ return make_pair(p.first / x, p.second / x); }
template<class T1, class T2> pair<T1, T2> &operator+=(pair<T1, T2> &p1, const pair<T1, T2> &p2){ return p1 = p1 + p2; }
template<class T1, class T2> pair<T1, T2> &operator-=(pair<T1, T2> &p1, const pair<T1, T2> &p2){ return p1 = p1 - p2; }
template<class T1, class T2, class U> pair<T1, T2> &operator*=(pair<T1, T2> &p, const U &x){ return p = p * x; }
template<class T1, class T2, class U> pair<T1, T2> &operator/=(pair<T1, T2> &p, const U &x){ return p = p / x; }
