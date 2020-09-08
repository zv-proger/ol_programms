/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0869 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m,  dt[15000]; cin >> n >> m;
    for (auto i = 0; i < n; i++) {
        cin >> dt[i];
    }
    sort(dt, dt + n);
    int ans = 0, l = 0, r = n - 1;
    while(l <= r) {
        ans++;
        if (dt[l] + dt[r] <= m) l++;
        r--;
    }
    cout << ans;
}