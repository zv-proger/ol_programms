/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0456 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int fb[20] = {1, 1};
int fib(int n) {
    if (fb[n]) return fb[n];
    return fb[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int x, y; cin >> x >> y;
    for (int i = 1; ; i++) {
        int c = y + fib(x - 2) * i;
        if (c % fib(x - 1) == 0) {
            cout << c / fib(x - 1) << ' ' << c / fib(x - 1) - i;
            return 0;
        }
    }
}