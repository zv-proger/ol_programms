/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 215 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

using pii = pair<int, int>;

template <class A, class B> pair<A, B> operator + (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f + b.f, a.s + b.s);}

vector<vector<short>> a, c;

bool f;

short & get(vector<vector<short>> &a, const pii &p) {
    f = true; static short bad;
    if (p.f < 0 || p.s < 0 || p.f >= a.size() || p.s >= a[p.f].size()) {
        f = false; return bad;
    }
    return a[p.f][p.s];
}

vector<pii> nghb = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(const pii &p) {
    queue<pii> q;
    q.push(p);
    get(c, p) = 2;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (auto &v : nghb) {
            auto next = p + v;
            if (get(c, next) == 2 || !f) continue;
            if (get(a, p) <= get(a, next)) {
                get(c, next) = 2;
                q.push(next);
            }
        }
    }
}

pii dfs(const pii &p) {
    get(c, p) = 1;
    for (auto &v : nghb) {
        if (get(c, p + v) > 0 || !f) continue;
        if (get(a, p) >= get(a, p + v)) {
            auto cand = dfs(p + v);
            if (get(a, cand) < get(a, p))
                return cand;
        }
    }
    return p;
}

void read() {
    int n, m; cin >> n >> m;
    a.assign(n, vector<short>(m));
    c = a;
    for (auto &x : a) {
        for (auto &y : x) {
            cin >> y;
        }
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (!get(c, {i, j})) {
                bfs(dfs({i, j}));
                ans ++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    read();
}