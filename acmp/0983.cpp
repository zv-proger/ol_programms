/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0983 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> dt;
    for (int i = 0; i < n; i++) {
        int t, w; cin >> t >> w;
        dt.push_back({w, {t, i}});
    }
    sort(dt.begin(), dt.end());
    long long cur = 0;
    vector<pair<int, int>> ans;
    for (auto &p: dt) {
        cur = max(cur, 1LL * p.first * p.second.first);
        ans.push_back({p.second.second, cur});
    }
    sort(ans.begin(), ans.end());
    for (auto &p: ans) {
        cout << p.second << endl;
    }
}