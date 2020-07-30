/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0540 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, m, r, dp[3][2002] = {0}, *cur = dp[0], *prev = dp[1], *pprev = dp[2]; cin >> n >> m >> r;

    for (int i = 1; i <= m; i++) {
        cin >> prev[i];
        prev[i] %= r;
    }
    for (int i = 1; i <= m; i++) {
        cur[i] = prev[i-1] + prev[i] + prev[i+1];
        cur[i] %= r;
    }
    for (int j = 2; j < n; j++) {
        swap(prev, pprev);
        swap(cur, prev);
        for (int i = 1; i <= m; i++) {
            cur[i] = 2 * prev[i-1] + prev[i] + 2 * prev[i+1];
            if (i != 1 && i != m) cur[i] += 2 * r - pprev[i] * (1 + (j > 2));
            cur[i] %= r;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cur[i] << ' ';
    }
}