/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0799 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dt(n);
    for (auto &x: dt) { cin >> x; }
    int mx = 0;
    for (auto &x: dt) { mx = max(mx, x); }
    bool f = mx == dt.front();
    int bst = -1;
    for (int i = 1; i < n - 1;  f |= mx == dt[i++]) {
        if (!f) continue;
        if (dt[i] % 10 != 5) continue;
        if (dt[i] <= dt[i + 1]) continue;
        bst = max(dt[i], bst);
    }
    int c = 0;
    for (auto &x: dt) { c += x > bst; }
    cout << (c + 1) % (n + 1);
}