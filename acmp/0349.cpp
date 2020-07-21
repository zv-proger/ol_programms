/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0349 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

vector<int> pr, lp;



int main() {
    int m, n; cin >> m >> n;
    lp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (auto p : pr) {
            if (p > lp[i] || i * p > n) break;
            lp[i * p] = p;
        }
    }
    bool f = false;
    for (auto p : pr) {
        if (p >= m && p <= n) {
            cout << p << endl;
            f = true;
        }
    }
    if (!f) cout << "Absent" << endl;
}