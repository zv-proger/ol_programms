/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 908 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A> void print(const A &a) { cout << a << ' '; }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
template <class... O> void println(O &...o) { print(o...); cout << endl; }
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }

int main() {
    int n; read(n);
    vector<int> dp(n+1, inf);
    dp[1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i + 1] = min (dp[i] + 1, dp[i + 1]);
        if (i * 2 <= n) dp[i * 2] = min (dp[i] + 1, dp[i * 2]);
        if (i * 3 <= n) dp[i * 3] = min (dp[i] + 1, dp[i * 3]);
    }
    doans(dp[n]);
}