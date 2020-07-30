/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0480 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;
const int MAXN = 181, MAXK = 81;

int main() {
    int dp[MAXK][MAXN] = {0}, dt[MAXN], ss[MAXN] = {0};
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dt[i];
    }
    for (int i = n; i; i--)
        ss[i] = ss[i+1] + dt[i];
    int k; cin >> k;
    for (int c = 1; c <= k; c++) {
        for (int i = n; i; i--) {
            for (int q = c; q; q--) {
                dp[c][i] = max(dp[c][i], ss[i] - dp[q][i + q]);
            }
        }
    }
    cout << dp[k][1];
}