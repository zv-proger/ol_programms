/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0128 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

pii operator+ (const pii &a, const pii &b) { return {a.first + b.first, a.second + b.second}; }


vector<vector<int>> pool;
int n;

int &arr(const pii &pos) {
    static int bad = -1;
    if (pos.first >= n || pos.first < 0) return bad;
    if (pos.second >= n || pos.second < 0) return bad;
    return pool[pos.first][pos.second];
}

void bfs(pii s) {
    vector<pii> to = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1},
                   {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    queue<pii> q; q.push(s);
    arr(s) = 1;
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for (auto &v: to) {
            if (arr(cur + v) == 0) {
                arr(cur + v) = arr(cur) + 1;
                q.push(cur + v);
            }
        }
    }
}

int main() {
    cin >> n; pool.assign(n, vector<int>(n));
    int xs, ys, xe, ye; cin >> xs >> ys >> xe >> ye;
    bfs({xs - 1, ys - 1});
    cout << pool[xe - 1][ye - 1] - 1;
}