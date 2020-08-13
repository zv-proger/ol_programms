/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0534 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
int dt[101], n, m, x;

int main() {
    FASTIO;
    cin >> n; for (int i = 1; i <= n; i++) { cin >> dt[i]; }
    cin >> m; for (int i = 1; i <= m; i++) { cin >> x; dt[x]--; }
    for (int i = 1; i <= n; i++) { cout << (dt[i] < 0 ? "yes" : "no") << endl; }
}