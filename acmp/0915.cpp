/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0915 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

vector<vector<int>> from = {
    {},
    {3, 5, 4, 2},
    {6, 1, 3, 4},
    {6, 5, 1, 2},
    {6, 5, 1, 2},
    {6, 3, 1, 4},
    {5, 3, 4, 2}
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dt(n, vector<int>(m));
    vector<vector<vector<int>>> dp(7, dt);
    for(auto &s : dt) for (auto &x : s) cin >> x;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 1; c < 7; c++) {
                if (!i && !j) {
                    dp[c][i][j] = c * dt[i][j]; continue;
                }
                dp[c][i][j] = -inf;
                for (auto &f: from[c]) {
                    if(j) dp[c][i][j] = max(dp[c][i][j], dp[f][i][j - 1] + c * dt[i][j]);
                    if(i) dp[c][i][j] = max(dp[c][i][j], dp[f][i - 1][j] + c * dt[i][j]);
                }
            }
        }
    }
    int ans = -inf;
    for (int i = 1; i < 7; i++) ans = max(ans, dp[i][n-1][m-1]);
    cout << ans;
}