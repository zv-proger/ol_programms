/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0816 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
map<int, set<int>> a, b;

void request() {
    string key; cin >> key;
    if (key == "ADD") {
        int x, y; cin >> x >> y;
        b[x].insert(y); a[y].insert(x);
    }
    if (key == "LISTSET") {
        int x; cin >> x;
        if (!a[x].size()) cout << -1;
        for (auto &c: a[x]) cout << c << ' ';
        cout << endl;
    }
    if (key == "LISTSETSOF") {
        int x; cin >> x;
        if (!b[x].size()) cout << -1;
        for (auto &c: b[x]) cout << c << ' ';
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    int t; cin >> t;
    for (; t--;) {
        request();
    }
}