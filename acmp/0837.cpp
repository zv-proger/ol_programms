/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0837 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool calc(int n, int m) {
    return m <= (n - 1) * (n - 2) / 2;
}

int main() {
    int t; cin >> t;
    for (; t--;) {
        int a, b; cin >> a >> b;
        cout << (calc(a, b)? "Yes": "No") << endl;
    }
}