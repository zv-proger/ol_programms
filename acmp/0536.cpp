/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0536 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, c, k, m = 1; cin >> n >> c >> k;
    string s; cin >> s;

    for (;k--;) m *= 10;

    vector<ll> dp(n);
    for (int i = 0; s[i]; i++) {
        for (int j = max(0, i-9); j <= i; j++) {
            if (i != j && s[j] == '0') continue;
            k = 0;
            for (int l = j; l <= i; l++) {
                k = k * 10 + s[l] - '0';
            }
            if (k > c) continue;
            dp[i] += j ? dp[j-1] : 1;
            dp[i] %= m;
        }
    }
    cout << dp[n - 1];
}