/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0343 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
pii operator+ (pii a, pii b) { return {a.first + b.first, a.second + b.second}; }

vector<pii> types[] = {
    {{}},
    {{1, 0}, {1, 1}, {0, 1}}, // 1
    {{0, 0}, {1, 0}, {1, 1}}, // 3
    {{0, 1}, {0, 0}, {1, 1}}, // 2
    {{0, 0}, {0, 1}, {1, 0}}, // 4
};

int n, m;
bool dt[51][51] = {0};

bool &get(pii x) {
    //cout << x.first << ' ' << x.second << endl;
    static bool bad = 1;
    if (x.first <= 0 || x.first > n || x.second <= 0 || x.second > m) return bad;
    return dt[x.first][x.second];
}

int main() {
    cin >> n >> m;
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int c, x, y; cin >> c >> x >> y;
        pii pos = {x, y};
        int cnt = 0;
        for (auto &d : types[c]) {
            cnt += get(pos + d);
        }
        if (cnt) continue;
        for (auto &d : types[c]) {
            get(pos + d) = 1;
        }
    }
    int ans = 0;
    for( int i = 1; i <= n; i++)
    for( int j = 1; j <= m; j++) {
        ans += get({i, j});
    }
    cout << ans;
}