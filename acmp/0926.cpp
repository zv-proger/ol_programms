/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0926 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int dt[50][50];

int main() {
    int n, all = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            all += dt[i][j] = c == 'C';
        }
    }
    all /= 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << 1 + (all > 0);
            all -= dt[i][j];
        }
        cout << endl;
    }
}