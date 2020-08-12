/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0654 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
using ll = long long;

int main() {
    FASTIO;
    int n; cin >> n;
    ll ans = 0, mx = 0, prev;
    for (int i = 1; i <= n; i++) {
        ll cur; cin >> cur;
        if (!mx) mx = prev = cur;
        mx = max(mx, cur);
        ans += max(0LL, cur - prev);
        prev = cur;
    }
    ans += mx - prev;
    cout << ans;
}