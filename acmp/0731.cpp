/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0731 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int sm, dt[30];
    bool gd[30], nd[30];
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c >> dt[i];
        sm += dt[i];
        gd[i] = c == '+';
    }
    int fr = 100;
    for (int i = 0; i < n; i++) {
        nd[i] = !!(dt[i] * 100 % sm);
        dt[i] = dt[i] * 100 / sm;
        fr -= dt[i];
    }
    for (int i = 0; i < n; i++) {
        if (fr && nd[i] && gd[i]) {
            dt[i]++;
            nd[i] = 0;
            fr --;
        }
    }
    for (int i = 0; i < n; i++) {
        if (nd[i] && fr) {
            dt[i]++;
            fr--;
        }
        cout << dt[i] << endl;
    }

}