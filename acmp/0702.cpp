/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0702 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const int n = 100;
bool pl[101][101];

int dfs(int i, int j) {
    if (i < 0 || i > n || j < 0 || j > n || !pl[i][j])
        return 0;
    pl[i][j] = 0;
    return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
}

int main() {
    int k; cin >> k;
    for (; k--;) {
        int i, l, ii, jj; cin >> i >> l >> ii >> jj;
        for (; i < ii; i++)
            for (int j = l; j < jj; j++)
                pl[i][j] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
}