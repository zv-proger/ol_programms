/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0715 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> a(n), b(n);
    for (auto &s: a) cin >> s;
    for (auto &s: b) cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += a[i][j] != b[i][j];
        }
    }
    cout << ans;
}