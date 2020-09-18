/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0874 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

vector<vector<int>> gr;
int n, k, m;
int ans = 0;
vector<int> color;

void step(int v) {
    if (v == n) {
        ++ans;
        return;
    }
    for (int i = 0; i < k; i++) {
        for (auto &x: gr[v]) {
            if (color[x] == i) goto nxt;
        }
        color[v] = i;
        step(v + 1);
nxt:;
    }
    color[v] = -1;
}

int main() {
    cin >> n >> k >> m;
    gr.resize(n);
    color.assign(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        gr[a-1].push_back(b-1);
        gr[b-1].push_back(a-1);
    }
    step(0);
    cout << ans << endl;
}
