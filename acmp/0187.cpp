/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0187 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[100][100];

int main() {    
    int n; cin >> n;
    dp[1][1] = 1;
    for (int i = 1; i < 2 * n; i++) {
        for (int j = max(1, i - n + 1); j < min (i + n, 2 * n); j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }
    cout << dp[2*n - 1][2*n - 1];
}