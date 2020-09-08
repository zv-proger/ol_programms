/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0472 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, m; cin >> n >> m;
    vector<int> dt(n); for(auto &x : dt) cin >> x;
    sort(ALL(dt));
    dt.push_back(1e9);
    int p = dt[0];
    for (int i = 1; i <= n; i++) {
        while (p < dt[i] && m >= 0) { m -= i; p++; }
        if (m < 0) {
            cout << p - 1;
            return 0;
        }
    }
}