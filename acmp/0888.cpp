/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0888 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0; int n; cin >> n;
    int t = 3;
    for (int x;cin >> x;) {
        if (x) {
            ans += t;
            t++;
        } else {
            t = max(3, t - 3);
        }
    }
    cout << ans;
}