/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0913 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

struct seg {
    int d, l, h;
    void read() {
        cin >> d >> l >> h;
    }
};

int main() {
    int n, m; cin >> n >> m;
    seg dt[1000];
    vector <int> speeds = {m};
    for (int i = 0; i < n; i++) {
        dt[i].read();
        if (dt[i].l < m) speeds.push_back(dt[i].l);
    }
    sort(ALL(speeds));
    int ans = m; double best_time = 1e20;
    for (; !speeds.empty(); speeds.pop_back()) {
        m = speeds.back();
        double tm = 0;
        for (int i = 0; i < n; i++) {
            tm += dt[i].d / 1.0 / m;
            if (m > dt[i].l) tm += dt[i].h;
        }
        if (tm + 1e-9 < best_time) {
            best_time = tm;
            ans = m;
        }
    }
    cout << ans;
}