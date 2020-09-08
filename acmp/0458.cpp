/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0458 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    vector<int> ord(n); for (auto &x: ord) cin >> x;
    string a; cin >> a;
    vector<string> dt(n);
    for (int i = 0; i < n; i++) {
        dt[i].resize(a.length() / n + (i < a.length() % n));
    }
    int j = 0;
    for (auto &x: ord) {
        for (auto &c: dt[x - 1]) {
            c = a[j++];
        }
    }
    for (int j = 0; ; j++) {
        for (int i = 0; i < n; i++) {
            if (!dt[i][j]) return 0;
            cout << dt[i][j];
        }
    }
}