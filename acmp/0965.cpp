/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0965 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> edgs;
vector<bool> usd, last_good;
int ans = 1e9, ansc, n;

int calc() {
    for (auto &p: edgs) {
        if (!usd[p.first] && !usd[p.second]) return -1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += usd[i];
    }
    return ans;
}

void step(int v) {
    if (v == n + 1) {
        auto c = calc();
        if (c < 0) return;
        if (ans > c) {
            ans = c; ansc = 0;
            last_good = usd;
        }
        ansc += ans == c;
        return;
    }
    step(v + 1);
    usd[v] = 1;
    step(v + 1);
    usd[v] = 0;
}

int main() {
    int m; cin >> n >> m;
    usd.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        edgs.push_back({a, b});
    }
    step(1);
    cout << ans << ' ' << ansc << endl;
    for (int i = 1; i <= n; i++) {
        if (last_good[i]) cout << i << ' ';
    }
}