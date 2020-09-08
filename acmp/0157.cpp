/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0157 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll fact[16];

int main() {
    fact[0] = 1;
    for (int i = 1; i < 16; i++) fact[i] = fact[i-1] * i;
    map<char, int> dt;
    string x; cin >> x;
    for (auto &c: x) {
        dt[c]++;
    }
    ll ans = fact[x.length()];
    for (auto &p: dt) {
        ans /= fact[p.second];
    }
    cout << ans;
}