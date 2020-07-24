/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0487 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m; cin >> n >> k >> m;
    vector<bool> is_win(n + 1);
    for (int i = 0; i <= n; i++) {
        is_win[i] = i % (k + 1);
    }
    for (; m--; n -= a) {
        int a; cin >> a;
        cout << (is_win[n] && is_win[n - a] ? 'F' : 'T') << endl;
    }
}