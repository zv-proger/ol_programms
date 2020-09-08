/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0966 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<pii> x;
    for (int i = 0; i < n; i++) {
        int l, r, d; cin >> l >> r >> d;
        x.push_back({l, d});
        x.push_back({r, -d});
    }
    sort(ALL(x));
    int j = 0, t; cin >> t;
    ll ans = 0, cd = 0;
    for (int i = 0; i < t; i++) {
        while (j < x.size() && x[j].first == i) {
            cd += x[j++].second;
        }
        ans = max(0LL, ans + cd);
    }
    cout << ans;
}