/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0431 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

string pl[50];
bool usd[50][50];
pii par[50][50];
int n;

inline bool check(const pii &a) {
    if (a.first < 0 || a.first >= n || a.second < 0 || a.second >= n) return 1;
    return usd[a.first][a.second];
}

inline void setv(const pii &a) {
    usd[a.first][a.second] = 1;
}

inline void setp(const pii &a, const pii &b) {
    par[a.first][a.second] = b;
}

inline pii operator +(const pii &a, const pii &b) {return {a.first + b.first, a.second + b.second}; }

int main() {
    cin >> n;
    pii s, e;
    for (int i = 0; i < n; i++) {
        cin >> pl[i];
        for (int j = 0; j < n; j++) {
            if (pl[i][j] == '#') {
                setv({i, j});
            }
            if (pl[i][j] == '@') {
                e = s;
                s = {i, j};
            }
            setp({i, j}, {-1, -1});
        }
    }
    queue<pii> q; q.push(s); setv(s);
    vector<pii> seeks = {{1, 2},{-1, 2},{1, -2},{-1, -2},{2, 1},{-2, 1},{2, -1},{-2, -1}};
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (auto sk: seeks) {
            if (check(cur + sk)) continue;
            setp(cur + sk, cur);
            setv(cur + sk);
            q.push(cur + sk);
        }
    }
    if (par[e.first][e.second] == (pii){-1, -1}) { cout << "Impossible" << endl; return 0; }
    while(e != s) {
        pl[e.first][e.second] = '@';
        e = par[e.first][e.second];
    }
    for (int i = 0; i < n; i++) {
        cout << pl[i] << endl;
    }
}