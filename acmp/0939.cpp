/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0939 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    int n, s = 0; cin >> n;
    vector<pii> dt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s += x;
        dt.push_back({x, i + 1});
    }
    sort(dt.begin(), dt.end());
    int t = 0;
    vector<int> ans;
    for (int l, r = l = 0; r <= n; r++) {
        if (t * 3 == s) {
            for (int i = 0; i < r; i++) {
                ans.push_back(dt[i].second);
            }
            break;
        }
        t += dt[r].first;
        while (t * 3 > s) {
            t -= dt[l++].first;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << ' ';
}