/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0696 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second
pii operator +(pii a, pii b) { return { a.first + b.first, a.s + b.s}; }

vector<string> src, cur_src; int n, m; 
set<char> keys = {'.', 'S', 'E'};

char &get(pii p) {
    static char bad = 'X';
    if (p.f < 0 || p.f >= n || p.s < 0 || p.s >= m) return bad;
    return cur_src[p.first][p.second];
}

pii s, e;

bool bfs() {
    queue<pii> q; q.push(s);
    get(s) = 1;
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (auto d: vector<pii>({{0, 1}, {0, -1}, {1, 0}, {-1, 0}})) {
            if (!keys.count(get(d + cur))) continue;
            get(d + cur) = 1;
            q.push(d + cur);
        }
    }
    return !keys.count(get(e));
}

vector<int> costs(4); string key = "RGBY";
int ans = -1, cur;

void step(int i) {
    if (i == 4) {
        cur_src = src;
        if (bfs()) {
            if (ans < 0 || ans > cur) ans = cur;
        }
        return;
    }
    step(i + 1);
    cur += costs[i]; keys.insert(key[i]);
    step(i + 1);
    cur -= costs[i]; keys.erase(key[i]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 4; i++) {
        cin >> costs[i];
    }
    src.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> src[i];
        for (int j = 0; j < m; j++) {
            if (src[i][j] == 'S') {
                s = {i, j};
            } else if (src[i][j] == 'E') {
                e = {i, j};
            }
        }
    }
    step(0);
    if (ans < 0) {
        cout << "Sleep";
    } else {
        cout << ans;
    }
}