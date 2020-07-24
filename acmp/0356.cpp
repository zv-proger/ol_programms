/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0356 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A> void print(A a) { cout << a << ' '; }
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}
template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

#define p f
#define w s

struct calcmin { static ll calc(const ll &a, const ll &b) { return min(a, b); } static const ll def = 1e18; };
struct calcmax { static ll calc(const ll &a, const ll &b) { return max(a, b); } static const ll def = -1; };

int e, f;
vector<pii> coins;

template <typename F> ll calc_dp() {
    int n = f - e;
    vector<ll> dp(n + 1, F::def);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &p : coins) {
            if (i - p.w < 0) continue;
            if (dp[i - p.w] == F::def) continue;
            dp[i] = F::calc(dp[i], dp[i-p.w] + p.p);
        }
    }
    if (dp[n] == F::def) doans ("This is impossible.");
    return dp[n];
}

int main() {
    read(e, f, coins);
    doans(calc_dp<calcmin>(), calc_dp<calcmax>());
}