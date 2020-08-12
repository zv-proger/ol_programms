/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0621 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

set<pii> unknown = {{-2, -2}};
set<pii> par[200][200];
int dt[200][200], n;

pii operator +(const pii &a, const pii &b) { return {a.first + b.first, a.second + b.second}; }
pii operator -(const pii &a, const pii &b) { return {a.first - b.first, a.second - b.second}; }
int dist(const pii &a, const pii &b) { return abs(a.first - b.first) + abs(a.second - b.second); }


int get_dt(const pii &a) {
    return dt[a.first][a.second];
}
set<pii> &get_par(const pii &a) {
    if (a.first < 0 || a.first >= n || a.second < 0 || a.second >= n) return unknown;
    return par[a.first][a.second];
}

int main() {
    cin >> n;
    queue<pii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dt[i][j];
            if (dt[i][j]) { q.push({i, j}); par[i][j].insert({i, j}); }
        }
    }
    vector<pii> napr = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        if (get_par(cur) == unknown) continue;
        for (pii &sk: napr) {
            pii nxt = cur + sk;
            if (get_par(nxt).empty()) {
                get_par(nxt) = get_par(cur);
                q.push(nxt);
                continue;
            }
            for (auto p: get_par(cur)) {
                if (dist(nxt, *get_par(nxt).begin()) == dist(nxt, p)){
                    get_par(nxt).insert(p);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto &prs = get_par({i, j});
            if (prs.size() != 1) cout << 0 << ' ';
            else cout << get_dt(*prs.begin()) << ' ';
        }
        cout << endl;
    }
}