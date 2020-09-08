/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0505 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using bs = vector<int>;
using ll = long long;

int hsh(const bs &a) {
    int sk = 8197, md = 1e9+9;
    ll ans = 0;
    for (auto &c: a) {
        ans = ans * sk + c; ans %= md;
    }
    return (int) ans;
}

map<int, int> tmpls;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, m, n; cin >> l >> m >> n;
    bs a(l);
    for (; m--;) {
        int c; cin >> c;
        for (auto &c: a) cin >> c;
        tmpls[hsh(a)] = c;
    }
    int ok = 0, bad = 0;
    for (; n--;) {
        for (auto &c: a) cin >> c;
        int h = hsh(a);
        if (tmpls.count(h)) { ok++; cout << tmpls[h] << endl; }
        else { bad++; cout << '-' << endl; }
    }
    cout << "OK=" << ok << " BAD=" << bad;
}