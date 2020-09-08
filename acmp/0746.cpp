/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0746 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool gr[300][300];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        gr[--a][--b] = 1;
        gr[b][a] = 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int c = 0;
            for (int k = 0; k <n; k++) {
                if (k == i || k == j) continue;
                c += gr[i][k] && gr[k][j];
            }
            ans += 1LL * c * (c - 1) / 2;
        }
    cout << ans / 2;
}