/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0668 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int calc() {
    int n, m; cin >> n >> m;
    if (n % 2 == 1 && m == 0) return -1;
    int ans = 0;
    ans += m / 2;
    n += m / 2;
    ans += n / 2;
    n %= 2;
    m %= 2;
    if (n && m) ans += 3;
    else if (n) ans += 4;
    else if (m) ans += 6;
    return ans;
}

int main() {
    cout << calc();
}