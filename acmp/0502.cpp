/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0502 с сайта acmp.ru
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
    int n; read(n);
    int dp[51][51] = {0}, dt[51][51];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            read(dt[i][j]);
        }
    }

    for (int c = 1; c <= n; c++) {
        for (int j = 1; j <= n; j++) {
            dp[c][j] = dp[c][j-1];
            for (int i = 1; i <= c; i++) {
                dp[c][j] = max(dp[c][j], dp[c - i][j - 1] + dt[i][j]);
            }
        }
    }

    doans(dp[n][n]);
}