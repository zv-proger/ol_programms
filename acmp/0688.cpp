/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0688 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;
using pff = pair<double, double>;
using pll = pair<long long, long long>;

template <class A, class B> pair<A, B> operator + (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f + b.f, a.s + b.s);}
template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
template <class A> A &get(vector<vector<A>> &a, const pii &p) {
    static A bad;
    if (p.f < 0 || p.s < 0 || p.f >= a.size() || p.s >= a[p.f].size()) return bad;
    return a[p.f][p.s];
}
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}
template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}

#define sqr(x) 1LL * (x) * (x)
ll dist(pii a, pii b) { return sqr(a.f-b.f) + sqr(a.s-b.s); }

int main() {
    pii sus, dog; cin >> sus >> dog;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        pii x; cin >> x;
        if (dist(sus, x) * 4 <= dist(dog, x)) {
            cout << i;
            exit(0);
        }
    }
    cout << "NO";
}