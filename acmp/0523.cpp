/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0523 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int dt[100], n; cin >> n;
    int sm = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> dt[i];
        sm += dt[i];
        mx = max(dt[i], mx);
    }
    int k; cin >> k;
    int l = mx - 1, r = sm;
    while (l < r - 1) {
        int m = (l + r + 1) / 2;
        int cnt = 0, cr = 0;
        for (int i = 0; i < n; i++) {
            if (cr + dt[i] > m) {
                cnt++; cr = 0;
            }
            cr += dt[i];
        }
        cnt += !!cr;
        if (cnt > k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r;
}