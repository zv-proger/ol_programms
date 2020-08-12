/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0788 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)

using ll = long long;
using pii = pair<int, int>;

pii dt[300000]; 

bool f(pii a, pii b) {
    return a.first - b.second > b.first - a.second;
}

int main() {
    FASTIO;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dt[i].first >> dt[i].second;
    }

    sort(dt, dt + n, f);

    bool f = true;
    ll d = 0;
    for (int i = 0; i < n; i++) {
        if (f) {
            d += dt[i].first;
        } else {
            d -= dt[i].second;
        }
        f = !f;
    }
    cout << d;
}