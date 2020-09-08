/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0576 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = n, s = n;
    for (int i = 2; i <= n; i++) {
        if (s % i == 0) ans -= ans / i;
        while (s % i == 0) s /= i;
    }
    cout << min(ans, n - 1);
}