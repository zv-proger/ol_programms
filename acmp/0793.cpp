/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0793 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int count(int x) {
    int ans = 0;
    while(x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int calc(int n) {
    int sm = count(n);
    int p = n;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            n /= i;
            sm -= count(i--);
        }
    }
    if (p != n) sm -= count(n);
    return !sm;
}

int main() {
    for (int x; cin >> x;) {
        cout << calc(x);
    }
}