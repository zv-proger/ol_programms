/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0562 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int gr[301][301];


int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            gr[i][j] = inf * (i != j);
        }
    }
    for (; m--;) {
        int a, b; cin >> a >> b;
        gr[a][b] = 0;
        gr[b][a] = min(1, gr[b][a]);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                gr[i][j] = min (gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, gr[i][j]);
        }
    }
    cout << ans;
}