/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0447 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 1;
    for (; n; n--) {
        ans *= n;
        while(ans % 10 == 0) ans /= 10;
        ans %= 10000;
    }
    cout << ans % 10;
}