/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0470 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

void print(const double &a) { cout << fixed << setprecision(6) << a << ' '; }
template <class A> void print(const A &a) { cout << a << ' '; }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
template <class... O> void println(const O &...o) { print(o...); cout << endl; }
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }

int main() {
    FASTIO;
    ll ps[101][101] = {0};
    int n, m, t; read(n, m, t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            read(ps[i][j]);
            ps[i][j] += ps[i-1][j];
            ps[i][j] += ps[i][j-1];
            ps[i][j] -= ps[i-1][j-1];
        }
    }
    for (;t--;) {
        int a, b, c, d; read(a,b,c,d);
        println(ps[c][d] - ps[a-1][d] - ps[c][b-1] + ps[a-1][b-1]);
    }
}