/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0916 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n, k; cin >> n >> k;
    vector<int> dt(n); for (auto &x: dt) cin >> x;
    sort(ALL(dt), greater<int>());
    int kf = 0, o = 0;
    long long ans = 0;
    for (auto &x : dt) {
        kf += o == 0; o = (o + k - 1) % k;
        ans += x * kf;
    }
    cout << ans;
}