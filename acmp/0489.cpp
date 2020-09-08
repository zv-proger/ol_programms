/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0489 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n * 2 - 1; i++) {
        int x; cin >> x;
        ans ^= x;
    }
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        ans ^= x; ans ^= -x;
    }
    cout << ans;
}