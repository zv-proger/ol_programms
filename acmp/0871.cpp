/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0871 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<int> clr;

void doyes() {
    cout << "YES";
    exit(0);
}

void dfs(int v, int p) {
    clr[v] = 1;
    for (auto x : gr[v]) {
        if (x == p) continue;
        if (clr[x] == 2) continue;
        if (clr[x] == 1) doyes();
        dfs(x, v);
    }
    clr[v] = 2;
}

int main() {
    int n, m; cin >> n >> m;
    gr.resize(n+1);
    clr.resize(n+1);

    for(;m--;) {
        int a, b; cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!clr[i]) dfs(i, 0);
    cout << "NO";
}