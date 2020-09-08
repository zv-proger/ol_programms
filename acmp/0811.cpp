/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0811 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool good[100][100], bad[100][100];

int n, m;
using pii = pair<int, int>;

void good_init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(i + j)) continue;
            good[i][j] = true ^ (i? good[i-1][j]: good[i][j-1]);
        }
    }
}

vector<pii> x[2], *bstV = x;

int check() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (good[i][j] ^ bad[i][j]) {
                ans ++;
                x[**good].push_back({i, j});
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            bad[i][j] = c == 'W';
        }
    }
    good_init();
    int bst = check();
    **good ^= true;
    good_init();
    int cur = check();
    if (cur <= bst) {
        bst = cur;
        bstV = &x[**good];
    }
    cout << bst << endl;
    for (auto &p: *bstV) {
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
}