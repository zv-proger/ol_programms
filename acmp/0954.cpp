/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0954 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

void print(const double &a) { cout << fixed << setprecision(6) << a << ' '; }
template <class A> void print(const A &a) { cout << a << ' '; }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
template <class... O> void println(O &...o) { print(o...); cout << endl; }
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }

int main() {
    int dp[100001] = {1};
    int n; read(n);
    for (int i = 0; i <= n; i++) {
        dp[i] += dp[i-1];
        if (i > 9) p[i] += dp[i-10];
        dp[i] %= 500000;
    }
    doans(dp[n] * 2);
}