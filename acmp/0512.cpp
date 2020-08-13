/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0512 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int dp[10][10][1<<10], *prev;
int n, m, k;
bool can[10][10];

int calc(int mal, int femal, int k) {
    if (k == 0) return 1;
    if (dp[k-1][mal][femal] >= 0) return dp[k-1][mal][femal];
    dp[k-1][mal][femal] = 0;
    for (int i = mal; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (can[i][j] && (femal & (1 << j)) != 0) {
                dp[k-1][mal][femal] += calc(i + 1, femal ^ (1 << j), k - 1);
            }
        }
    }
    return dp[k-1][mal][femal];
}

int main() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            can[i][j] = c == 'Y';
        }
    }
    cout << calc(0, (1 << m) - 1, k);
}