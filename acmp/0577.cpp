/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0577 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int dt[10];

void f(int x) {
    while (x) {
        dt[x%10]++;
        x /= 10;
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <=m; j++) {
            f(i*j);
        }
    }

    for (int i = 0; i < 10; i++) cout << dt[i] << endl;
}