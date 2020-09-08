/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0957 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int dt[1 << 6][1 << 6], last = 0;

void step(int lx, int ly, int rx, int ry, int x, int y) {
    if (lx == rx - 1) return;
    int mx = (lx + rx) / 2, my = (ly + ry) / 2;
    int cur = ++last;
    if (x < mx) { dt[mx][my] = dt[mx][my - 1] = cur; }
    if (x >= mx) { dt[mx - 1][my] = dt[mx - 1][my - 1] = cur; }
    if (y < my) { dt[mx][my] = dt[mx - 1][my] = cur; }
    if (y >= my) { dt[mx][my - 1] = dt[mx - 1][my - 1] = cur; }
    if (x < mx && y < my) {
        step(lx, ly, mx, my, x, y);
        step(lx, my, mx, ry, mx - 1, my);
        step(mx, ly, rx, my, mx, my - 1);
        step(mx, my, rx, ry, mx, my);
    } else if (x >= mx && y < my) {
        step(lx, ly, mx, my, mx - 1, my - 1);
        step(lx, my, mx, ry, mx - 1, my);
        step(mx, ly, rx, my, x, y);
        step(mx, my, rx, ry, mx, my);
    } else if (x < mx && y >= my) {
        step(lx, ly, mx, my, mx - 1, my - 1);
        step(lx, my, mx, ry, x, y);
        step(mx, ly, rx, my, mx, my - 1);
        step(mx, my, rx, ry, mx, my);
    } else if (x >= mx && y >= my) {
        step(lx, ly, mx, my, mx - 1, my - 1);
        step(lx, my, mx, ry, mx - 1, my);
        step(mx, ly, rx, my, mx, my - 1);
        step(mx, my, rx, ry, x, y);
    }
}

int main() {
    int k, x, y; cin >> k >> x >> y;
    int n = 1 << k;
    step(0, 0, n, n, y - 1, x - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dt[i][j] << ' ';
        }
        cout << endl;
    }
}