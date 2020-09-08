/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0988 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

void solve() {
    unsigned long long k, p; cin >> k >> p;
    if (p < 64 && k > (1ULL << p) - 1) {
        cout << "No solution" << endl; return;
    }
    unsigned long long i = 1;
    while (i < k) {
        i = 2 * i + 1;
    }
    while (k != i + 1) {
        if (i < k) k -= i + 1;
        else i /= 2;
    }
    int ans = 1; while (i > 0) { i /= 2; ans++;}
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}