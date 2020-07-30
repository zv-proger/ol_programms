/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0113 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, ans = 0; cin >> n;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '0') continue;
            dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans;
}