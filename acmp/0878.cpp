/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0878 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
using pii = pair<char, int>;

int main() {
    vector<pii> dt;
    for (int i = 1; i < 27; i++) {
        char c; cin >> c; dt.push_back({c, i});
    }
    sort(ALL(dt));
    for (int i = 0; i < 26; i++) {
        if (dt[i].first < 'A' + i) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES" << endl;
    for (auto &p: dt) {
        cout << p.second << ' ';
    }
}