/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0911 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    char c; int x; cin >> c >> x;
    vector<int> dt;
    while (x) {
        dt.push_back(x % 3);
        x /= 3;
    }
    int o = 0;
    for (auto &x: dt) {
        x += o; o = 0;
        if (x > 1) {
            x -= 3; o = 1;
        }
        if (c == 'L') x = -x;
    }
    if (o) dt.push_back(o * (c == 'L' ? -1: 1));
    long long p = 1;

    set<long long> l, r;

    for (int i = 0; i < dt.size(); i++, p *= 3) {
        if (!dt[i]) continue;
        (dt[i] > 0 ? l: r).insert(p);
    }
    cout << "L:";
    for (auto &x: l) {
        cout << x << ' ';
    }
    cout << endl << "R:";
    for (auto &x: r) {
        cout << x << ' ';
    }
}