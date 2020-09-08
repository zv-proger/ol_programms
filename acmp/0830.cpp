/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0830 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = uint64_t;

void calc(int x, int *o, int *z) {
    x++;
    for (int i = 0; i < 30; i++) {
        int p = 1 << i, np = p << 1;
        o[i] = x / np * p + max(0, x - x / np * np - p);
        z[i] = x / np * p + min(p, x - x / np * np);
    }
}

int main() {
    int a, b; cin >> a >> b;
    int oa[30], ob[30], za[30], zb[30];
    calc(a, oa, za);
    calc(b, ob, zb);
    __int128_t ans = 0;
    for (int i = 0; i < 30; i++) {
        ans += (__int128_t) oa[i] * zb[i] * (1 << i);
        ans += (__int128_t) za[i] * ob[i] * (1 << i);
    }
    string s;
    for(; ans; ans /= 10) { s = char('0' + ans % 10) + s; }
    cout << s;
}