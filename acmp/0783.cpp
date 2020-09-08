/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0783 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second
pii operator +(pii a, pii b) { return { a.first + b.first, a.s + b.s}; }

vector<string> pl; int n;
map<char, char> rev = {{'W', 'B'}, {'B', 'W'}, {'X', 'X'}};

char &get(pii a) {
    static char bad = 'X';
    if (a.f < 0 || a.f >= n || a.s < 0 || a.s >= n) return bad;
    return pl[a.f][a.s];
}

bool dfs(pii cur) {
    if (get(cur) == 'X') return 0;
    char nxtv = rev[get(cur)];
    get(cur) = 'X';
    for (auto &d: vector<pii>({{1, 0},{0, 1},{-1, 0},{0, -1}})) {
        pii nxt = cur + d;
        if (nxtv == get(nxt)) dfs(nxt);
    }
    return 1;
}

int main() {
    string s;
    while (cin >> s) {
        pl.push_back(s);
    }
    n = pl.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += dfs({i, j});
        }
    }
    cout << ans;
}