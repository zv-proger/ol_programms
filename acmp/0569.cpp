/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0569 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    int n, k; cin >> n >> k;
    set<pii> a;
    vector<pii> ans(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x - k) a.insert({x - k, i});
    }
    while (!a.empty()) {
        auto l = *a.begin(), r = *a.rbegin();
        a.erase(a.begin()); a.erase(--a.end());
        r.first += l.first;
        ans[l.second] = {r.second, -l.first};
        if (r.first) a.insert(r);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}