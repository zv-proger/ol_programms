/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0832 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

int main() {
    int n; cin >> n;
    for (; n--;) {
        ll a, b, c; cin >> a >> b >> c;
        if ((a % 2 != b % 2 || a % 2 != c % 2 || c % 2 != b % 2) &&
            (a + b != 0) && (a + c != 0) && (c + b != 0) ||
            (a + b + c == 1)
        )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}