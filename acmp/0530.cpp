/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0530 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
using pii = pair<int, int>;

map<pii, char> conv;

int main() {
    int n, m; cin >> m >> n;
    vector<string> a(n), b(n);
    for (auto &s: a) cin >> s;
    for (auto &s: b) cin >> s;
    cin >> conv[{'0','0'}] >> conv[{'0','1'}] >> conv[{'1','0'}] >> conv[{'1','1'}];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << conv[{a[i][j], b[i][j]}];
        }
        cout << endl;
    }
}