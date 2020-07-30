/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0217 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}

int main() {
    int m; cin >> m;
    vector<pii> dt(m); for (auto &x : dt) cin >> x;
    int n; cin >> n;
    vector<int> pos(n + 1, -inf); for (int i = 1; i <= n; i++) cin >> pos[i];
    vector<pii> dp(n + 1, {0, -inf});
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int p = i - 1; p >= 0; p--) {
                if (pos[p] + dt[j].f > pos[i]) continue;
                if (dp[p].s > pos[i]) continue;
                if (dp[i].f > dp[p].f + 1) continue;
                if (dp[i].f < dp[p].f + 1 || dp[i].s > dt[j].s + pos[i]) {
                    dp[i].f = dp[p].f + 1;
                    dp[i].s = dt[j].s + pos[i];
                }
            }
        }
    }
    cout << dp[n].f << endl;
}