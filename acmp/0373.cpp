/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0373 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 102;

struct {
    int dp[MAXN][MAXN];
    bool can[MAXN][MAXN];
} pl[2];

int dt[MAXN][MAXN];

int main() {
    auto *cur = pl, *prev = pl + 1;
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dt[i][j];
        }
    }
    int ans = cur -> dp[1][1] = dt[1][1];
    cur -> can[1][1] = 1;
    for (; --k;) {
        swap(cur, prev);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cur -> can[i][j] = prev -> can[i-1][j] || prev -> can[i][j-1] || prev -> can[i+1][j] || prev -> can[i][j+1];
                if (cur -> can[i][j]) {
                    cur -> dp[i][j] = max(max(prev -> dp[i-1][j] * prev -> can[i-1][j], prev -> dp[i+1][j] * prev -> can[i+1][j]),
                                          max(prev -> dp[i][j-1] * prev -> can[i][j-1], prev -> dp[i][j+1] * prev -> can[i][j+1])) + dt[i][j];
                    ans = max(ans, cur -> dp[i][j]);
                }
            }
        }
    }
    cout << ans;
}