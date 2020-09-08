/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0961 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> pr(n), cr(n);
    for (auto &s: pr) cin >> s;
    for (auto &s: cr) cin >> s;
    set<char> u, l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pr[i][j] != cr[i][j]) {
                (isupper(cr[i][j])?u:l).insert(cr[i][j]);
                (isupper(pr[i][j])?u:l).insert(pr[i][j]);
            }
        }
    }
    l.erase('.');
    cout << u.size() + l.size() << endl;
    for (auto &c: l) cout << c;
    for (auto &c: u) cout << c;
}