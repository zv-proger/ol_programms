/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0281 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int count(int a) {
    int ans = 0;
    for (; a; a >>= 1) {
        ans += a & 1;
    }
    return ans;
}

int main() {
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ans += coun(i) >= m;
    }
    cout << ans << endl;
}