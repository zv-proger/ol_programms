/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0955 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

bool pool[101][101];
int n, m;

void dfs(const int &i, const int &j) {
    if (i > n || i < 1 || j > m || j < 1) return;
    if (pool[i][j]) return;
    pool[i][j] = true;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main() {
    int k; cin >> n >> m >> k;
    for (; k--;) {
        int i, j; cin >> i >> j;
        pool[i][j] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += !pool[i][j];
            dfs(i, j);
        }
    }
    cout << ans;
}