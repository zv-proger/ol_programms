#import<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[101];
int d[101];
int n, k, i, j;
#define y for (
#define u [d]
void f(int v) {
    if (v u < 0) return;
    v u = -1;
    y auto p: g[v]) f(p.first);
}

main() {
    y cin >> n >> k; cin >> k >> i >> j;)
        g[k].push_back({i, j});

    y k = 1; k++ < n; cout << k u << ' ') {
        memset(d,-1,404);
        1 u = 0;
        set<int> b;
        y i = n; i--;)
            y j = 0; j++ < n; )
                y auto p: g[j])
                    if (j u >= 0 && j - k && p.first u < j u + p.second)
                        b.insert(i ? 0: j),
                        p.first u = j u + p.second;
        y int v: b) f(v);
    }
}