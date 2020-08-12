/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0601 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<map<int, int>> gr(n + 1);
    for (; m--;) {
        int a, b, c; cin >> a >> b >> c;
        gr[a][c] = b;
        gr[b][c] = a;
    }
    int cur = 1, k; cin >> k;
    for (; k--;) {
        int c; cin >> c;
        if (!gr[cur].count(c)) {cout << "INCORRECT"; return 0; }
        cur = gr[cur][c];
    }
    cout << cur;
}