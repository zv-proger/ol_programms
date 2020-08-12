/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0432 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool pool[201][201];
int n, m;

void dfs(const int &i, const int &j) {
    if (i >= n || i < 0 || j >= m || j < 0) return;
    if (pool[i][j]) return;
    pool[i][j] = true;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            pool[i][j] = c != '#';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += !pool[i][j];
            dfs(i, j);
        }
    }
    cout << ans;
}