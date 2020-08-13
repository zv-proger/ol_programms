/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0967 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int s(int a, int k) {
    int ans = 0;
    for (; a; a /= k) ans += a % k;
    return ans;
}

int main() {
    int n, k1, k2; cin >> n >> k1 >> k2;
    vector<int> dt(n);
    for (auto &x: dt) {
        cin >> x; x = s(x, k1) * s(x, k2);
    }
    sort(dt.begin(), dt.end());
    for (auto &x: dt) cout << x << ' ';
}