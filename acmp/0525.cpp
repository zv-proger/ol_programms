/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0525 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const int MX = 11;

int main() {
    int n; cin >> n;
    vector<vector<int>> dp(MX, vector<int>(n+1));
    for (int i = 0; i < MX; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i - 1];
        for (int j = 1; j < MX; j++) {
            dp[j][i] = dp[j-1][i];
            if ((1 << j) <= i) {
                dp[j][i] += dp[j][i - (1 << j)];
            }
        }
    }
    cout << dp[MX - 1][n];
}