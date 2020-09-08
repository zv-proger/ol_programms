/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0459 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
using pii = pair<int, int>;
#define f first
#define s second
pii operator + (pii a, pii b) { return {a.f + b.f, a.s + b.s}; }
pii operator - (pii a, pii b) { return {a.f - b.f, a.s - b.s}; }

map<pii, set<pii>> gr;
string prior = "NESW";
map<char, pii> to = {{'N', {1, 0}}, {'S', {-1, 0}}, {'W', {0, 1}}, {'E', {0, -1}}};
map<pii, char> rev = {{{1, 0}, 'N'}, {{-1, 0}, 'S'}, {{0, 1}, 'W'}, {{0, -1}, 'E'}};
map<pii, pii> par;

int main() {
    pii start, cur = {0, 0};
    char c;
    while (cin >> c) {
        gr[cur].insert(cur + to[c]);
        gr[cur + to[c]].insert(cur);
        cur = cur + to[c];
    }
    par[cur] = cur;
    queue<pii> q; q.push(cur);
    while (!q.empty()) {
        cur = q.front(); q.pop();
        for (auto c: prior) {
            auto nxt = cur + to[c];
            if (!gr[cur].count(nxt)) continue;
            if (par.count(nxt)) continue;
            par[nxt] = cur;
            q.push(nxt);
        }
    }
    cur = {0, 0};
    string ans;
    while (cur != par[cur]) {
        ans = rev[cur - par[cur]] + ans;
        cur = par[cur];
    }
    cout << ans;
}