/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0707 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<int, pair<int, pair<char, int>>> par;
queue<string> q;

string beat(string s, int i, bool nw = true) {
    if (i < 0 || s == "") return s;
    int l = i, r = i;
    s.insert(i, nw, s[i]);
    while (l >= 0 && s[l] == s[i]) l--;
    while (s[r + 1] == s[i]) r++;
    if (r - l < 3) return s;
    s.erase(l + 1, r - l);
    return beat(s, l, 0);
}

bool f = true;
int calc(string s) {
    int cr = hash<string>()(s);
    for (int i = 0; s[i]; i++) {
        if (i && s[i-1] == s[i]) continue;
        string ps = beat(s, i);
        if (ps.length() > 15) continue;
        int nxt = hash<string>()(ps);
        if (par.count(nxt)) continue;
        par[nxt] = {cr, {s[i], i}};
        if (ps == "") { f = false; return cr; }
        q.push(ps);
    }
    return cr;
}

int main() {
    string s; cin >> s;
    q.push(s);
    while (f) {
        calc(q.front());
        q.pop();
    }
    int st = hash<string>()(s), end = hash<string>()("");
    list<pair<char, int>> ans;
    for (; end != st; end = par[end].first)
        ans.push_front(par[end].second);
    cout << ans.size();
    for (auto p: ans) cout << ' ' << p.first << p.second;
}