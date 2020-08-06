/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0848 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

map<int, map<int, bool>> pal;

int main() {
    string s;
    cin >> s;
    for (int i = 0; s[i]; i++) {
        pal[i][i] = true;
        if (i) pal[i-1][i] = s[i] == s[i-1];
    }
    for (int l = 2; s[l]; l++) {
        for (int i = 0; s[i + l]; i++) {
            if (s[i] == s[i+l]) pal[i][i+l] = pal[i+1][i+l-1];
        }
    }
    vector<int> st(s.length(), 0);
    vector<int> dp(s.length(), 1);
    for (int i = 1; s[i]; i++) {
        dp[i] = dp[i-1] + 1; st[i] = i;
        for (int j = 0; j < i; j++) {
            if (pal[j][i]) {
                if (!j) {
                    dp[i] = 1;
                    st[i] = 0;
                } else if (dp[j-1] + 1 < dp[i]) {
                    dp[i] = dp[j-1] + 1;
                    st[i] = j;
                }
            }
        }
    }
    vector<string> ans;
    for (int i = s.length() - 1; i >= 0; i = st[i] - 1) {
        ans.push_back(s.substr(st[i], i - st[i] + 1));
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << endl;
}