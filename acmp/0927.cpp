/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0927 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7.5;

int main() {
    string s; cin >> s;
    ll dp[2][2][10] = {0}, (*cur)[10] = dp[0], (*prev)[10] = dp[1];
    for (int c = 1; c < s[0] - '0'; c++) {
        cur[1][c] = 1;
        if (c > 1) cur[0][c - 1] = 1;
    }
    for (int t = 1; s[t]; t++) {
        int c = s[t] - '0', p = s[t - 1] - '0' + 20;
        swap(cur, prev);
        ll s1 = 0, s0 = 0;
        for (int i = 0; i < 10; i++) {
            s1 = (s1 + prev[1][i]) % MOD;
            s0 = (s0 + prev[0][i]) % MOD;
            cur[0][i] = cur[1][i] = 0;
        }
        for (int i = 0; i <= c; i++) {
            int j = (p - c + i) % 10;
            cur[1][i] = s1 - prev[1][i];
            if (j != i) cur[1][i] -= prev[1][j];
            cur[1][i] = (2LL * MOD + cur[1][i]) % MOD;
        }
        if (c > 0)
        for (int i = 0; i <= c - 1; i++) {
            int j = (p - c + i + 1) % 10;
            cur[0][i] = s1 - prev[1][i];
            if (j != i && j>=0 && j < 10) cur[0][i] -= prev[1][j];
            cur[0][i] = (2LL * MOD + cur[0][i]) % MOD;
        }
        c += 10; p -= 1;
        for (int i = 0; i <= 9; i++) {
            if (c - i > 9) continue;
            int j = (p - c + i) % 10;
            cur[1][i] += s0 - prev[0][i];
            if (j != i && j>=0 && j < 10) cur[1][i] -= prev[0][j];
            cur[1][i] = (2LL * MOD + cur[1][i]) % MOD;
        }
        for (int i = 0; i <= 9; i++) {
            if (c - i > 10) continue;
            int j = (p - c + i + 1) % 10;
            cur[0][i] += s0 - prev[0][i];
            if (j != i && j>=0 && j < 10) cur[0][i] -= prev[0][j];
            cur[0][i] = (2LL * MOD + cur[0][i]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += cur[1][i];
        ans %= MOD;
    }
    cout << ans << endl;
}