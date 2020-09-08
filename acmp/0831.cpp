/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0831 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool msimp(int i) {
    if (i == 1) return false;
    for (int j = 2; 1LL * j * j <= i; j++) {
        if (i % j == 0) return false;
    }
    return true;
}

int f(int x) {
    int ans = 0;
    while(x) { ans += x % 10; x /= 10; }
    return ans;
}

int main() {
    int a, b; cin >> a >> b;

    int best = -1;
    for (int i = a; i <= b; i++) {
        if (!msimp(i)) continue;
        if (best < 0 || f(best) <= f(i)) best = i;
    }
    cout << best << endl;
}