/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0542 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n) {
        ans = ans * 2 + n % 2;
        n /= 2;
    }
    cout << ans;
}