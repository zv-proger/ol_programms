/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0543 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, w, d, p; cin >> n >> w >> d >> p;
    cout << (((n-1) * n * w / 2 - p) / d - 1 + n) % n + 1;
}