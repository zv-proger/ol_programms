block: funcs
template <class A> void print(A a) { cout << a << ' '; }
@#
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
@#
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
@#
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}
@#
template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
@#
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}
@#
template <class A> void read(A a) { cin << a; }
@#
template <class A, class... O> void read(A a, O... o) { read(a); read(o...); }
@#
