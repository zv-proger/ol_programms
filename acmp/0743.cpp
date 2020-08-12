/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0743 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int m; cin >> m;
    map<string, vector<string>> gr;
    for (; m--;) {
        string f, s; cin >> f >> s >> s;
        gr[f].push_back(s);
    }
    string s, e; cin >> s >> e;
    queue<string> q; q.push(s); q.push("");
    set<string> usd = {s};

    int ans = 0;
    while (true) {
        auto cur = q.front(); q.pop();
        if (cur == "") {
            ans ++;
            if (q.empty()) break;
            q.push("");
            continue;
        }
        if (cur == e) {
            cout << ans;
            return 0;
        }
        for (auto nxt: gr[cur]) {
            if (!usd.count(nxt)) {
                usd.insert(nxt);
                q.push(nxt);
            }
        }
    }
    cout << -1;
}