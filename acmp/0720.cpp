/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0720 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    double r, l; cin >> r >> l;
    r /= l;
    int ans = 0;
    for (int h = r - 1e-9; h; h--) {
        int d = sqrt(r * r - h * h) + 1e-9;
        if (h) ans += d;
    }
    cout << ans * 4;
}