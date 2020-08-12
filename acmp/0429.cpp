/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0429 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int stat[1001] = {0};
vector<int> gr[1001];

int dfs(int i = 1, int f = 1) {
    if (stat[i]) return stat[i];
    if (f) {
        for (auto v : gr[i]) {
            if (dfs(v, !f) == 1) return stat[i] = 1;
        }
        for (auto v : gr[i]) {
            if (dfs(v, !f) == 3) return stat[i] = 3;
        }
        return stat[i] = 2;
    } else {
        for (auto v : gr[i]) {
            if (dfs(v, !f) == 2) return stat[i] = 2;
        }
        for (auto v : gr[i]) {
            if (dfs(v, !f) == 3) return stat[i] = 3;
        }
        return stat[i] = 1;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        char c; int p, v; cin >> c >> p;
        gr[p].push_back(i);
        if (c == 'L')  {
            cin >> v;
            stat[i] = v ? v < 0 ? 2 : 1 : 3;
        }
    }
    dfs();
    //for (int i = 1; i <= n; i++) { cout << i << ' ' << stat[i] << endl;}
    cout << (stat[1] == 1 ? "+1" : stat[1] == 2 ? "-1" : "0");
}