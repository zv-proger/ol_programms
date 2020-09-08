/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0230 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second

pii operator+ (pii a, pii b) { return {a.f + b.f, a.s + b.s}; }

char pl[102][102];
#define get(a) pl[(a).f][(a).s]

map<int, vector<pair<pair<vector<pii>, vector<pii>>, pair<int, pii>>>> gr = {
    { 1,
        {
            {{{{-1, 1}, {-1, 0}}, {{0, 1}}}, {3, {0, 1}}},
            {{{{-1, 1}, {0, 1}}, {{-1, 0}}}, {3, {-1, 0}}},
            {{{}, {{-1, 1}, {-1, 0}}}, {0, {-1, 1}}},
            {{{}, {{-1, 1}, {0, 1}}}, {0, {-1, 1}}},
            {{{{1, -1}, {1, 0}}, {{0, -1}}}, {3, {0, -1}}},
            {{{{1, -1}, {0, -1}}, {{1, 0}}}, {3, {1, 0}}},
            {{{}, {{1, -1}, {1, 0}}}, {0, {1, -1}}},
            {{{}, {{1, -1}, {0, -1}}}, {0, {1, -1}}},
        }
    },
    { 2,
        {
            {{{{1, 1}, {1, 0}}, {{0, 1}}}, {3, {0, 1}}},
            {{{{1, 1}, {0, 1}}, {{1, 0}}}, {3, {1, 0}}},
            {{{}, {{1, 1}, {1, 0}}}, {0, {1, 1}}},
            {{{}, {{1, 1}, {0, 1}}}, {0, {1, 1}}},
            {{{{-1, -1}, {-1, 0}}, {{0, -1}}}, {3, {0, -1}}},
            {{{{-1, -1}, {0, -1}}, {{-1, 0}}}, {3, {-1, 0}}},
            {{{}, {{-1, -1}, {-1, 0}}}, {0, {-1, -1}}},
            {{{}, {{-1, -1}, {0, -1}}}, {0, {-1, -1}}},
        }
    },
};

void dfs(pii a, int t) {
    if ((get(a) & t) == t) return;
    get(a) |= t;
    for (auto &p: gr[t]) {
        bool fl = true;
        auto &r = p.s;
        auto &f = p.f.s;
        auto &b = p.f.f;
        for (auto v: b) 
            fl &= get(a + v) == 7;
        for (auto v: f) 
            fl &= get(a + v) != 7;
        if (fl) 
            dfs(a + r.s, t ^ r.f);
    }
}


int main() {
    map<char, char> from = {{0, '.'}, {1, '/'}, {2, '\\'}, {3, 'X'}, {7, '*'}};
    map<char, char> to = {{'.', 0}, {'/', 1}, {'\\', 2}, {'X', 0}, {'*', 7}};
    memset(pl, 7, sizeof(pl));
    int n, m; cin >> n >> m;
    pii s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == 'X') s = {i, j};
            pl[i][j] = to[c];
        }
    }

    dfs(s, 1);
    dfs(s, 2);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << from[pl[i][j]];
        } cout << endl;
    }
}