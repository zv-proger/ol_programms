/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0484 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> fb;

void initFb() {
    ll c, p = c = 1;
    for (int i = 0; i < 50; i++) {
        fb.push_back(c);
        swap(c, p += c);
    }
}

ll to(ll x) {
    ll ans = 0;
    for (int i = 49; i >= 0; i--) {
        if (x >= fb[i]) {
            ans |= 1LL << i;
            x -= fb[i];
        }
    }
    return ans;
}

ll from(ll x) {
    ll ans = 0;
    for (int i = 49; i >= 0; i--) {
        if (x & (1LL << i)) {
            ans += fb[i];
        }
    }
    return ans;
}

int main() {
    initFb();
    ll x; cin >> x;
    x = to(x + 1);

    while(x > 1) {
        cout << from(x) - 1 << ' ';
        x /= 2;
    }
}