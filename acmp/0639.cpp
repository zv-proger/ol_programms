/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0639 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)

int main() {
    FASTIO;
    int n; cin >> n;
    vector<pair<double, string>> dt;
    for (; n--;) {
        int m; cin >> m;
        for (; m--;) {
            string s; double a; cin >> a >> s;
            dt.push_back({a, s});
        }
    }
    sort(ALL(dt));
    reverse(ALL(dt));
    cout << dt.size() << endl;
    for (auto &p: dt) {
        cout << fixed << setprecision(2) << p.first << ' ' << p.second << endl;
    }
}