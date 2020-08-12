/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0630 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    pii dt[10000];
    for (int i = 0; i < n; ++i) {
        int s, e; cin >> s >> e;
        dt[i] = {s, e};
    }
    sort(dt, dt + n);
    if (dt[0].first != 0 || dt[n-1].second != 10000) goto no;
    for (int i = 1; i < n; i++) {
        if (dt[i].first > dt[i-1].second) goto no;
        if (dt[i].second <= dt[i-1].second) goto no;
        if (dt[i].first == dt[i-1].first) goto no;
        if (i < n-1 && dt[i+1].first <= dt[i-1].second) goto no;
    }

    //yes:
    cout << "Accepted" << endl; return;
    no:
    cout << "Wrong Answer" << endl; return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (; t--;) solve();
}