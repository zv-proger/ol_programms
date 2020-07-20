block: defines
#define f first
@#
#define s second
@#
block: types
using ll = long long;
@#
using pii = pair<int, int>;
@#
using pff = pair<double, double>;
@#
using pll = pair<ll, ll>;
@#
block: funcs
template <class A, class B> pair<A, B> operator + (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f + b.f, a.s + b.s);}
@#
template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
@#
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
@#
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}
@#
