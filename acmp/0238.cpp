/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0238 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

inline pii operator +(const pii &a, const pii &b) { return {a.first + b.first, a.second + b.second}; }
pii readPii() { pii a; cin >> a.first >> a.second; return a; }

int n, m;
bool usd[101][101];

bool check(const pii &a) {
    if (a.first < 1 || a.first > n || a.second < 1 || a.second > m)
        return 1;
    return usd[a.first][a.second];
}

void setv(const pii &a) {
    usd[a.first][a.second] = 1;
}

int main() {
    cin >> n >> m;
    pii s = readPii();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> usd[i][j];
        }
    }

    int k;
    map<pii, vector<pii>> gr;
    for (cin >> k;k--;) {
        gr[readPii()].push_back(readPii());
    }
    set<pii> exits;
    for (cin >> k;k--;) {
        exits.insert(readPii());
    }
    vector<pii> seeks = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans = 1;
    queue<pii> q; q.push(s); q.push({-1, -1});
    setv(s);
    while (true) {
        pii cur = q.front(); q.pop();
        if (cur == pii(-1, -1)) {
            if (q.empty()) break;
            ans ++;
            q.push(cur);
            continue;
        }
        if (exits.count(cur)) {
            cout << ans; return 0;
        }
        for (auto sk: seeks) {
            if (check(sk + cur)) {
                continue;
            }
            setv(sk + cur);
            q.push(sk + cur);
        }
        for (auto nxt: gr[cur]) {
            if (check(nxt)) {
                continue;
            }
            setv(nxt);
            q.push(nxt);
        }
    }
    cout << "Impossible";
}