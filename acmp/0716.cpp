/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0716 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    double pr, cr, l = 30, r = 4000; cin >> cr;
    string stp = "";
    for (; --n; ) {
        swap(pr, cr);
        string st; cin >> cr >> st;
        if (abs(cr - pr) < 1e-9) {
            if (st != stp && stp != "") {
                if (r > cr) l = max(l, 2 * cr - r);
                if (l < cr) r = min(r, 2 * cr - l);
            }
            continue;
        }
        if (st == "closer") {
            if (cr > pr) l = max(l, (cr + pr) / 2);
            else r = min(r, (cr + pr) / 2);
        } else {
            if (cr < pr) l = max(l, (cr + pr) / 2);
            else r = min(r, (cr + pr) / 2);
        }
        stp = st;
    }
    cout << fixed << setprecision(10) << l << ' ' << r;
}