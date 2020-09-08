/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0101 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int n;

int step(bool (*pl)[10], int h, int k) {
    int ans = 0;
    if (k == 1) {
        for (int i = h; i < n; i++) for (int j = 0; j < n; j++) {
            ans += !pl[i][j];
        }
        return ans;
    }
    if (n - h < k) return 0;
    for (int i = h; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!pl[i][j]) {
                bool npl[10][10];
                memcpy(npl, pl, sizeof(npl));
                if (i < n - 1 && j < n - 2) npl[i+1][j+2] = 1;
                if (i < n - 2 && j < n - 1) npl[i+2][j+1] = 1;
                if (i < n - 1 && j > 1) npl[i+1][j-2] = 1;
                if (i < n - 2 && j > 0) npl[i+2][j-1] = 1;
                for (int l = 1; l + i < n; l++) {
                    npl[i+l][j] = 1;
                    if (j + l < n) npl[i+l][j+l] = 1;
                    if (j >= l) npl[i+l][j-l] = 1;
                }
                ans += step(npl, i + 1, k - 1);
            }
    return ans;
}

int main() {
    int k; cin >> n >> k;
    bool dt[10][10] = {0};
    cout << step(dt, 0, k);
}