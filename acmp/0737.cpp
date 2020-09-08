/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0737 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll hsh(const map<char, int> &cnt) {
    ll ans = 0, p = 1301, md = 1e14+11;
    for (auto &x: cnt) {
        ans = (ans * p + x.second) % md;
    }
    return ans;
}

map<char, int> strt = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}}, cur;

void doans(int n, int a, int b) {
    cout << n << endl << a << ' ' << b;
    exit(0);
}

string a, b;
void check(int len) {
    map<ll, int> dt;
    cur = strt;
    int l = 0, r = 0;
    for (; r < len; r++) { cur[a[r]]++; }
    for (; a[r]; r++, l++) {
        dt[hsh(cur)] = l + 1;
        cur[a[l]]--;
        cur[a[r]]++;
    }
    dt[hsh(cur)] = l + 1;
    cur = strt;
    l = 0, r = 0;
    for (; r < len; r++) { cur[b[r]]++; }
    for (; b[r]; r++, l++) {
        if (dt.count(hsh(cur))) doans(len, dt[hsh(cur)], l + 1);
        cur[b[l]]--;
        cur[b[r]]++;
    }
    if (dt.count(hsh(cur))) doans(len, dt[hsh(cur)], l + 1);
}

int main() {
    cin >> a >> b;
    for (int i = min(a.length(), b.length()); i; i--) {
        check(i);
    }
    cout << 0;
}