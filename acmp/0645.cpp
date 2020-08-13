/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0645 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ba, bb, bv = 1e9;
    for (int i = 1; i * i <= n; i++) {
        int a = i, b = n / a, v = n - a * b + b - a;
        if (v < bv) {ba = a, bb = b, bv = v; }
    }
    cout << ba << ' ' << bb;
}