/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0570 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool calc() {
    char pl[1000][1000];
    int l, r, t, b, n, m; cin >> n >> m;
    l = m, r = 0, t = n, b = 0;
    for (int i = 0; i < n; i++) {
        cin >> pl[i];
        for (int j = 0; j < m; j++) {
            if (pl[i][j] == '.') continue;
            l = min (l, j); r = max(r, j);
            t = min (t, i); b = max(b, i);
        }
    }
    if (r < l) return 0;
    int a = max(max(r - l + 1, b - t + 1) - 4, 1);
    for (int i = max(min(t + 2, b - a - 1), 1); i <= min(max(t + 2, b - a - 1), n - 2); i++) {
        for (int j = max(min(l + 2, r - a - 1), 1); j <= min(max(l + 2, r - a - 1), m - 2); j++) {
            for (int l = i; l < i + a; l++) {
                for (int k = j; k < j + a; k++) {
                    if (pl[l][k] == '.')
                        goto nxt;
                }
            }
            return 1;
            nxt:;
        }
    }
    return 0;
}

int main() {
    cout << (calc() ? "SQUARE": "CIRCLE");
}