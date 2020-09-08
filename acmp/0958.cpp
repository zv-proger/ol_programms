/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0958 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, n; cin >> n >> k;
    bool gr[400][400];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            gr[i][j] = c == '-';
        }
    vector<vector<int>> ways;
    for (int i = 0; i < k; i++) {
        ways.push_back({});
        int c; cin >> c >> c;
        while (c != n) {
            ways.back().push_back(c - 1);
            cin >> c;
        }
    }
    auto &c = ways[0];
    for (size_t i = 1; i < ways.size(); i++) {
        auto &w = ways[i];
        vector <bool> res;
        bool fl = 0;
        size_t f, s = f = 0;
        while (f < c.size() || s < w.size()) {
            if (f == c.size()) { res.push_back(0); s++; continue; }
            if (s == w.size()) { res.push_back(1); f++; continue; }
            int a = c[f], b = w[s];
            fl = gr[a][b];
            (fl ? f : s) ++;
            res.push_back(fl);
        }
        vector<int> rres;
        s = f = 0;
        for (size_t i = 0; i < res.size(); i++) {
            rres.push_back(res[i] ? c[f++]: w[s++]);
        }
        c = rres;
    }
    cout << 1 << ' ';
    for (auto &x: c) cout << x + 1 << ' ';
    cout << n;
}