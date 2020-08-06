/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0631 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<int, int> csh;

inline int calc(int n) {
    if (n == 1) return 0;
    if (csh.count(n)) return csh[n];
    int l = 1, r = n;
    while (l < r - 1) { // calc(i) + 2, calc(n - i) + 1
        int m = (l + r) / 2;
        if (calc(m) + 2 <= calc (n - m) + 1) {
            l = m;
        } else {
            r = m;
        }
    }
    return csh[n] = max(calc(l) + 2, calc(n - l) + 1);
}

int main() {
    int n; cin >> n;
    cout << calc(n) << endl;
}