/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0137 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18 + 7;

ll a[100][100], b[100][100];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) a[i][j] = inf;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] == inf || a[k][j] == inf) continue;
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    memcpy(b, a, sizeof(a));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] == inf || a[k][j] == inf) continue;
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (b[i][j] == inf ? 0 : b[i][j] == a[i][j] ? 1 : 2) << ' ';
        }
        cout << endl;
    }
}