/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0982 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second
pii operator + (pii a, pii b) { return {a.f + b.f, a.s + b.s}; }

vector<string> pl_ar(8);

char pl(pii a) {
    if (a.f > 8 || a.f < 1 || a.s > 8 || a.s < 1) return 'X';
    return pl_ar[a.f-1][a.s-1];
}

set<pii> cur, usd;
vector<pii> ds = {{1, 1},{1, -1},{-1, 1},{-1, -1}};
void dfs(pii c, char s = 0) {
    if (!s) s = pl(c);
    if (usd.count(c)) return;
    usd.insert(c);
    for (auto d: ds) {
        if (pl(c + d) == '.' || pl(c + d) == s) continue;
        if (pl(c + d + d) != '.') continue;
        cur.insert(c + d);
        dfs(c + d + d, s);
    }
}

int main() {
    for (auto &s: pl_ar) cin >> s;
    set<pii> aW, aB;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (pl({i, j}) == '.') continue;
            cur.clear(); usd.clear();
            dfs({i, j});
            (pl({i, j}) == 'W'? aW: aB).insert(cur.begin(), cur.end());
        }
    }
    auto pr = [] (set<pii> d) {
        if (d.empty()) return;
        pii x = *d.begin(); d.erase(*d.begin());
        cout << '(' << x.f << ", " << x.s << ')';
        for (auto &x: d)
            cout << ", (" << x.f << ", " << x.s << ')';
        cout << endl;
    };
    cout << "White: " << aW.size() << endl;
    pr(aW);
    cout << "Black: " << aB.size() << endl;
    pr(aB);
}