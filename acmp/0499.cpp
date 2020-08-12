/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0499 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, k, s = 0; cin >> n >> k;
    int a, b, c, d, e, f;
    cin >> a >> d >> b >> e >> c >> f;
    if (a + b + c <= k) s = max(s, d + e + f);
    if (a + b     <= k) s = max(s, d + e    );
    if (a +     c <= k) s = max(s, d +     f);
    if (    b + c <= k) s = max(s,     e + f);
    if (a         <= k) s = max(s, d        );
    if (    b     <= k) s = max(s,     e    );
    if (        c <= k) s = max(s,         f);
    cout << (s >= n ? "YES" : "NO");
}