/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0351 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

#define cost second
#define last first

const int inf = 1e9;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<char, pii> dp;
    for (int i = 0; s[i]; i++) {
        int cur = i ? inf : 0;
        if (dp.count(s[i]) && i - dp[s[i]].last <= k) {
            dp[s[i]].last = i;
            cur = dp[s[i]].cost;
        }
        for (auto &p : dp) {
            if (i - p.second.last <= k) {
                cur = min (cur, p.second.cost + 1);
            }
        }
        dp[s[i]] = {i, cur};
    }
    cout << dp[s[n-1]].cost << endl;
}