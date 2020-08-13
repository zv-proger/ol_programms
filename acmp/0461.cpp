/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0461 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int dt[1001], k; cin >> k;
    for (int i = 0; i < k; i++) cin >> dt[i];
    sort(dt, dt + k);
    int ans = 0;
    for (int i = 0; i < (k + 2) / 2; i++) {
        ans += (dt[i] + 2) / 2;
    }
    cout << ans;
}