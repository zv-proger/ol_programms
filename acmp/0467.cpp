/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0467 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n; cin >> n; n *= 2;
    int dt[1000];
    for (int i = 0; i < n; i++) {
        cin >> dt[i];
    }
    dt[n++] = 0; dt[n++] = 1e9+.5;
    sort(dt, dt + n);
    bool f = 0;
    int ans = 0, prv;
    for (int i = 0; i < n; ) {
        int cr = dt[i];
        bool p = f;
        while(i < n && dt[i] == cr) { i++, f ^= 1; }
        if (!p && f) { prv = cr; }
        if (p && !f) { ans = max(ans, cr - prv); }
    }
    cout << ans;
}