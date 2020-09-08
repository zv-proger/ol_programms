/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0814 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool simp[10000];

void init() {
    for(int i = 2; i*i < 10000; i++) {
        if (simp[i]) {
            simp[i] = 0; continue;
        }
        if (!simp[i]) {
            simp[i] = 1;
            for (int j = i * i; j < 10000; j += i) {
                simp[j] = 1;
            }
        }
    }
}

int main() {
    init();
    int n; cin >> n;
    int ans = 0;
    for (int i = 2; i * 2 <= n; i++) {
        ans += simp[i] && simp[n-i];
    }
    cout << ans;
}