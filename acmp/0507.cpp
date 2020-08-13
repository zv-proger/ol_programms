/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0507 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

struct state{
    int x[4];
    state() { x[0] = x[1] = x[2] = x[3] = 0; }
};

vector<state> ans;

bool usd[100], gr[4][4];
int n;

int hsh(const state &x) {
    return x.x[0] + 3 * x.x[1] + 9 * x.x[2] + 27 * x.x[3];
}

void dfs(state &v) {
    if (usd[hsh(v)]) return;
    usd[hsh(v)] = true;
    bool f = true;
    for (int i = 0; i < n; i++) {
        if (!v.x[i]) continue;
        for (int j = 0; j < n; j++) {
            if (!v.x[j] || i == j && v.x[j] < 2) continue;
            if (gr[i][j]) {
                f = false;
                v.x[j] --;
                dfs(v);
                v.x[j] ++;
            }
        }
    }
    if (f) ans.push_back(v);
}

int main() {
    cin >> n;
    state st;
    for (int i = 0; i < n; i++) {
        cin >> st.x[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> gr[i][j];
        }
    }
    dfs(st);
    cout << ans.size() << endl;
    for (auto &p : ans) {
        for (int i = 0; i < n; i++) {
            cout << p.x[i] << ' ';
        }
        cout << endl;
    }
}