/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0407 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

template <class A> void print(A a) { cout << a << ' '; }
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

int main() {
    vector<int> coins; int total; read(coins, total);
    vector<int> dp(total + 1, inf); dp[0] = 0;
    for (int i = 1; i <= total; i++) {
        for (auto &x : coins) {
            if (i - x < 0) continue;
            dp[i] = min(dp[i], dp[i-x] + 1);
        }
    }
    if (dp[total] == inf) doans(-1);
    doans(dp[total]);
}