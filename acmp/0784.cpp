/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0784 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a, b; cin >> a >> a >> b;
    set<long long> pa;
    while(a) {
        pa.insert(a);
        a /= 2;
    }
    while(b) {
        if (pa.count(b)) { cout << b; return 0; }
        b /= 2;
    }
}