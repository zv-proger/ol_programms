/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0424 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;


bool f(long long x) {
    if (x < 10) return true;

    static map<long long, bool> csh;

    if (csh.count(x)) return csh[x];

    bool ans = false;
    for (int i = 2; i < 10; i++) {
        ans |= !f((x + i - 1) / i);
    }
    return csh[x] = ans;
}

int main() {
    long long a; cin >> a;
    cout << (f(a) ? "Stan wins.": "Ollie wins.");
}