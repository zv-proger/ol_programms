/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0635 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using pii = pair<int, int>;

int main() {
    int n, m; cin >> n >> m;
    vector<int> ans;
    vector<pii> dt;
    for (int i = 0; i < n; i++) {
        int id, taskc, tm; cin >> id >> taskc >> tm;
        if (!taskc) continue;
        dt.push_back({taskc, id});
    }
    n = dt.size();
    sort(ALL(dt), greater<pii>());
    for (int i = 0; i < n && dt[i].first && (dt[i].first == dt[0].first || dt[i].first > dt[n/2 - 1].first); i++) {
        ans.push_back(dt[i].second);
    }
    for (int i = 0; i < m; i++) {
        int id, taskc, tm; cin >> id >> taskc >> tm;
        if (taskc) ans.push_back(id);
    }
    sort(ALL(ans));
    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << ' ';
}