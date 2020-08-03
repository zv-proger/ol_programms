/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0683 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int inf = 1e9+7.5;

int main() {
    int n; cin >> n;
    if (n < 3) {cout << 0; return 0;}
    vector<int> dt(n); for (int i = 0; i < n; i++) cin >> dt[i];
    map<pii, int> dp;
    for (int len = 2; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            int r = l + len;
            dp[{l, r}] = inf;
            for (int c = l + 1; c < r; c++) {
                dp[{l, r}] = min(dp[{c, r}] + dp[{l, c}] + (dt[l] + dt[r]) * dt[c], dp[{l, r}]);
            }
        }
    }

    cout << dp[{0, n-1}];
}