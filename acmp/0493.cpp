/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0493 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    char a[102][102];
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += a[i][j] != '*' && a[i-1][j] != '*' && a[i+1][j] != '*' && a[i][j-1] != '*' && a[i][j+1] != '*';
        }
    }
    cout << ans;
}