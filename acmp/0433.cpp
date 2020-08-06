/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0433 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    map<int, int> was = {{0, 1}};
    ll ans = 0, cur = 0;
    for (auto &c : s) {
        cur += c == 'a';
        cur -= c == 'b';
        ans += was[cur];
        was[cur]++;
    }
    cout << ans;
}