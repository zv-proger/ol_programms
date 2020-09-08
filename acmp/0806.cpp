/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0806 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using gnom = pair<pair<int, int>, int>;
#define a first.first
#define b first.second
#define i second

bool cmp(gnom f, gnom s) {
    return f.b - s.a > s.b - f.a;
}

int main() {
    int n; cin >> n;
    gnom dt[100000];
    for (int i = 0; i < n; i++) {
        cin >> dt[i].a;
        dt[i].i = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> dt[i].b;
    }
    sort(dt, dt + n, cmp);
    int rtime = dt[0].b, ltime = 0;
    for (int i = 1; i < n; i++) {
        ltime += dt[i].a;
        rtime = min(rtime, ltime + dt[i].b);
    }
    if (ltime >= rtime) {
        cout << -1;
    } else
        for (int i = 0; i < n; i++) {
            cout << dt[i].i << ' ';
        }
}