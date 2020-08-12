/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0804 с сайта acmp.ru
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

pii operator +(const pii &a, const pii &b) { return {a.first + b.first, a.second + b.second}; }

unsigned pool[1000][1000];

unsigned &pl(const pii &p) {
    return pool[p.first][p.second];
}

int main() {
    int n, m; cin >> n >> m;
    pii rab = {1, 1}, tig, exi = {n - 2, m - 2};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c; 
            if (c == 'T') tig = {i, j};
            pool[i][j] = c == '#' ? -1 : 1e9;
        }
    }
    queue<pii> q; q.push(exi);
    pl(exi) = 1;
    vector<pii> dlts = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (auto &dlt: dlts) {
            if (pl(dlt + cur) != 1e9) continue;
            pl(dlt + cur) = pl(cur) + 1;
            q.push(cur + dlt);
        }
    }
    cout << pl(rab) - 1 << endl << (pl(rab) < pl(tig) ? "Yes" : "No");
}