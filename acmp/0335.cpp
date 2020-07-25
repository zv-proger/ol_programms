/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0335 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int INF = 1e9 + 0.003;
const int MOD = 1000000009;

using ll = long long;
using pii = pair<int, int>;

void print(const double &a) { cout << fixed << setprecision(6) << a << ' '; }
template <class A> void print(const A &a) { cout << a << ' '; }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
template <class... O> void println(O &...o) { print(o...); cout << endl; }
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}

map<int, vector<int>> to;

void init() {
    vector<int> simp;
    for (int i = 101; i < 999; i++) {
        bool f = true;;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) {
                f = false;
                break;
            }
        }
        if (f) simp.push_back(i);
    }
    for (auto &x : simp) {
        to[x/10].push_back(x % 100);
    }
}

int main() {
    int n; read(n);
    init();
    unsigned long long dp[2][100] = {0}, *cur = dp[0], *prev = dp[1];
    for (auto &p: to) {
        for (auto &t : p.second) {
            cur[t] ++;
        }
    }
    for (int i = 3; i < n; i++) {
        swap(prev, cur);
        for (int i = 0; i < 100; i++)
            cur[i] = 0;
        for (auto &p : to) {
            for (auto &t : p.second) {
                cur[t] += prev[p.first];
                cur[t] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 100; i++) {
        ans += cur[i];
        ans %= MOD;
    }

    cout << ans;
}