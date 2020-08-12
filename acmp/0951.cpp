/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0951 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

bool pool[3000][3000];
int n, m;

inline void setv(const int &a, const int &b) {
    pool[a][b] = true;
}

inline bool check(const int &a, const int &b) {
    if (a < 0 || a >= n || b < 0 || b >= m) return true;
    return pool[a][b];
}


int main() {
    int k; cin >> n >> m >> k;
    queue<pii> q;
    for (; k--;) {
        int a, b; cin >> a >> b;
        setv(a - 1, b - 1);
        q.push({a - 1, b - 1});
    }
    q.push({-1, 0});
    int ans = 0;
    while (true) {
        int a = q.front().first, b = q.front().second; q.pop();
        if (a < 0) {
            if (q.empty()) break;
            ans++; q.push({-1, 0}); continue;
        }
        if (!check(a - 1, b)) { q.push({a - 1, b}); setv(a - 1, b); }
        if (!check(a + 1, b)) { q.push({a + 1, b}); setv(a + 1, b); }
        if (!check(a, b - 1)) { q.push({a, b - 1}); setv(a, b - 1); }
        if (!check(a, b + 1)) { q.push({a, b + 1}); setv(a, b + 1); }
    }
    cout << ans;
}