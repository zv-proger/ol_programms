/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 406 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using st = size_t;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<double, int>> dt1;
    vector<pair<double, char>> dt2;
    map<char, int> cnt;
    st n, m; cin >> n >> m;
    for (st i = 0; i < n; i++) {
        char c; double x; cin >> c >> x;
        dt1.push_back({x, i});
    }
    for (st j = 0; j < m; j++) {
        char c; cin >> c; cnt[c]++;
    }
    for (auto p: cnt) {
        dt2.push_back({1.0 * p.second / m, p.first});
    }
    char c = 'a';
    while (c <= 'z') {
        if (!cnt.count(c))
            dt2.push_back({0, c});
        c++;
    }
    sort(dt1.begin(), dt1.end());
    sort(dt2.begin(), dt2.end());
    double dp[26][26] = {0};
    for (st i = 0; i < 26 * 26; i++) dp[i/26][i%26] = 30;
    int pr[26][26] = {0}; memset(pr, -1, sizeof(pr));
    for (st i = 0; i < n; i++) {
        for (int j = i; j < 26; j++) {
            if (!i) dp[i][j] = abs(dt1[i].first - dt2[j].first), pr[i][j] = j;
            else dp[i][j] = dp[i-1][j-1] + abs(dt1[i].first - dt2[j].first), pr[i][j] = j;
            if (j > i && dp[i][j-1] < dp[i][j]) {
                dp[i][j] = dp[i][j-1], pr[i][j] = pr[i][j-1];
            }
        }
    }
    vector<pair<int, char>> ans;
    for (int j = 25, i = n - 1; i >= 0; i--, j--) {
        j = pr[i][j]; assert(j >= 0);
        ans.push_back({dt1[i].second, dt2[j].second});
    }
    sort(ans.begin(), ans.end());
    for (auto &p: ans) cout << p.second << endl;
}