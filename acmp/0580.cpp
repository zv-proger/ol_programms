/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0580 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, r; cin >> a >> b >> c >> r;
    double p = a + b + c; p /= 2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    cout << (s / p + 1e-5 > r ? "YES" : "NO");
}