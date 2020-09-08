/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0189 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int fact(int k) {
    int ans = 1;
    for (int i = 1; i<=k; i++)
        ans *= i;
    return ans;
}

bool usd[13];

void step(int n, int k) {
    if (n == 0) return;
    int i = 1;
    while (k >= fact(n - 1)) {
        i++; k -= fact(n-1);
    }
    int j = 0;
    while (i) {
        j++;
        if (!usd[j]) i--;
    }
    usd[j] = 1; cout << j << ' ';
    step(n - 1, k);
}

int main() {
    int n, k; cin >> n >> k;
    step(n, k - 1);
}