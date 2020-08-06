/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0566 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

struct pos_t {
    int a, b, c;
    pos_t(const int &x = 0,const int &y = 0,const int &z = 0) {
        a = x, b = y, c = z;
    }
};

pii dp[101][101][101];
bool usd[101][101][101];

int main() {
    int k, a, b, c; cin >> a >> b >> c >> k;
    queue<pos_t> q; q. push( {a, b, c} );
    usd[a][b][c] = true;
    while(!q.empty()) {
        auto &pos = q.front(); q.pop();
        int o = dp[pos.a][pos.b][pos.c].second;
        int c = dp[pos.a][pos.b][pos.c].first;
        if (pos.a > 0) {
            dp[pos.a - 1][pos.b][pos.c] = 
             max(dp[pos.a - 1][pos.b][pos.c], { o + 1 >= k ? c + 1 : c, o + 1 >= k ? 0 : o + 1});
            if (!usd[pos.a - 1][pos.b][pos.c]) {
                usd[pos.a - 1][pos.b][pos.c] = true;
                q.push({pos.a - 1, pos.b, pos.c});
            }
        }
        if (pos.b > 0) {
            dp[pos.a][pos.b - 1][pos.c] = 
             max(dp[pos.a][pos.b - 1][pos.c], { o + 2 >= k ? c + 1 : c, o + 2 >= k ? 0 : o + 2});
            if (!usd[pos.a][pos.b - 1][pos.c]) {
                usd[pos.a][pos.b - 1][pos.c] = true;
                q.push({pos.a, pos.b - 1, pos.c});
            }
        }
        if (pos.c > 0) {
            dp[pos.a][pos.b][pos.c - 1] = 
             max(dp[pos.a][pos.b][pos.c - 1], { o + 3 >= k ? c + 1 : c, o + 3 >= k ? 0 : o + 3});
            if (!usd[pos.a][pos.b][pos.c - 1]) {
                usd[pos.a][pos.b][pos.c - 1] = true;
                q.push({pos.a, pos.b, pos.c - 1});
            }
        }
    }
    cout << dp[0][0][0].first;
}