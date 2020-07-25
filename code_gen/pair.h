block: defines
#define f first
@#
#define s second
@#
block: types
using pii = pair<int, int>;
@#
using pff = pair<double, double>;
@#
using pll = pair<long long, long long>;
@#
block: funcs
template <class A, class B> pair<A, B> operator + (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f + b.f, a.s + b.s);}
@#
template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
@#
template <class A> A &get(vector<vector<A>> &a, const pii &p) {
    static A bad;
    if (p.f < 0 || p.s < 0 || p.f >= a.size() || p.s >= a[p.f].size()) return bad;
    return a[p.f][p.s];
}
@#
