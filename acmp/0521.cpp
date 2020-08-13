/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0521 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int f(int x) {
    if (x < 3) return 0;
    if (x & 1) return f(x*3+1) + 1;
    return f(x/2) + 1;
}

int main() {
    int a, b; cin >> a >> b;
    int ans = 0;
    for (; a <= b; a++) ans += f(a);
    cout << ans;
}