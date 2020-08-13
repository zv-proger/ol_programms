/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0579 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x; vector<int> dt(x);
    int p = 0, n = 0, pc = 0, nc = 0;
    for (auto &x: dt) {
        cin >> x;
        (x > 0? p: n) += x;
        (x > 0? pc: nc)++;
    }
    if (p > -n) {
        cout << pc << endl;
        for (int i = 0; i < x; i++) 
            if (dt[i] > 0) {
                cout << i + 1 << ' ';
            }
    } else {
        cout << nc << endl;
        for (int i = 0; i < x; i++) 
            if (dt[i] <= 0) {
                cout << i + 1 << ' ';
            }
    }
}