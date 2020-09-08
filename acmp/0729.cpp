/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0729 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> pr;

void init(int n) {
    pr.resize(n);
    for (int i = 0; i < n; i++) {
        pr[i] = i;
    }
}

int par(int x) {
    if (x == pr[x]) return x;
    return pr[x] = par(pr[x]);
}

void merge(int a, int b) {
    a = par(a); b = par(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    pr[a] = b;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> dt(n);
    for (auto &x: dt) cin >> x;
    init(n + 1);
    for (; m--;) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }
    map<int, int> ans;
    for (int i = 0; i < n; i++) {
        ans[par(i + 1)] += dt[i];
    }
    for (auto &p: ans) {
        cout << p.first << ' ' << p.second << endl;
    }
}