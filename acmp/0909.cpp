/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0909 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second
pii operator + (pii a, pii b) { return {a.f + b.f, a.s + b.s}; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> pl_arr;
    for (int i = 0; i < n; i++) {
        string k; cin >> k;
        pl_arr.push_back(k);
    }

    auto pl = [&](pii a) -> char& {
        static char c = '-';
        if (a.f < 0 || a.f >= n || a.s < 0 || a.s >= m) return c;
        return pl_arr[a.f][a.s];
    };

    
    function<int(pii)> bfs = [&](pii a) -> int {
        if (pl(a) == '-') return 0;
        int ans = pl(a) == 'X' ? 1 : 2;
        pl(a) = '-';
        queue<pii> q; q.push(a);
        while (!q.empty()) {
            auto a = q.front(); q.pop();
            for (auto &d: vector<pii>({{0, 1},{-1, 0},{1, 0},{0, -1}})) {
                if (pl(d + a) == '-') continue;
                ans |= pl(d + a) == 'X' ? 1 : 2;
                pl(d + a) = '-';
                q.push(a + d);
            }
        }
        return ans;
    };

    int ans[4] = {0};
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[bfs({i, j})]++;
    cout << ans[2] << ' ' << ans[3] << ' ' << ans[1];
}