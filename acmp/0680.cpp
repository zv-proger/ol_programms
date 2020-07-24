/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 680 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A> void print(A a) { cout << a << ' '; }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }

int main() {
    int n; read(n);
    vector<ll> r(n + 1);
    r[1] = 1;
    auto g = r, b = r;
    for (int i = 2; i <= n; i++) {
        r[i] = g[i-1] + b[i-1];
        g[i] = r[i-1] + b[i-1];
        b[i] = g[i-1] + r[i-1];
    }
    doans(r[n] + g[n] + b[n]);
}