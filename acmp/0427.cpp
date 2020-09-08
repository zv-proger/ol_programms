/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0427 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int dt[10000];

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> dt[i];
    }
    sort(dt, dt + n);
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        if (mx < dt[i] - 1) break;
        mx += dt[i];
    }
    cout << mx + 1;
}