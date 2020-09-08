/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0475 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n = 0;
    int dt[100'000];
    for (int i = 0; cin >> dt[i]; i++) {
        n++;
    }
    sort(dt, dt + n);
    for (int i = 2; i < n; i++) {
        if (dt[i] - dt[i-1] != dt[i-1] - dt[i-2]) {
            cout << "No"; exit(0);
        }
    }
    cout << "Yes";
}