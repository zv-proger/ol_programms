/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0116 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int dt[1000] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        stack<pii> st;
        char s[1001]; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') dt[j]++; else dt[j] = 0;
            int l = j;
            while (!st.empty() && st.top().first >= dt[j]) {
                l = st.top().second;
                ans = max(ans, st.top().first * (j - st.top().second));
                st.pop();
            }
            st.push({dt[j], l});
        }
        while(!st.empty()) {
            ans = max(ans, st.top().first * (m - st.top().second));
            st.pop();
        }
    }
    cout << ans;
}