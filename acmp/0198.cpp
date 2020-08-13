/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0198 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int flr(double a) {
    int x = a - 0.5;
    if (abs(x - a) > abs(x + 1 - a)) x ++;
    if (abs(x - a) > abs(x + 1 - a)) x ++;
    return x;
}

int main() {
    int n; cin >> n;
    double pool[100][101], *dt[100];
    for (int i = 0; i < n; i++) dt[i] = pool[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> dt[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (abs(dt[j][i]) > 1e-9) {
                swap(dt[i], dt[j]);
                break;
            }
        }
        for (int j = n; j >= i; j--) {
            dt[i][j] /= dt[i][i];
        }
        for (int l = 0; l < n; l++) {
            if (i == l) continue;
            for (int j = n; j >= i; j--) {
                dt[l][j] -= dt[i][j] * dt[l][i];
            }
        }
    }
    for (int i = 0; i < n; i++) cout << flr(dt[i][n]) << ' ';
}