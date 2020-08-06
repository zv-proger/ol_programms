/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0646 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, k; cin >> n >> k;
    vector<int> dt(n + 1);
    for (int i = 1; i <= n; i++) cin >> dt[i];

    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1));
    dp[0][0] = 2;

    ll bads = 2;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= dt[j]) {
                for (int q = 0; q < j; q++) {
                    dp[i][j] += dp[i - dt[j]][q];
                }
            }
            bads += dp[i][j];
        }
    }
    cout << max(0LL, (1LL << n) - bads);
}