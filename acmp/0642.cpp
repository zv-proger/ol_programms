/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0642 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n, s; cin >> n >> s;
    vector<int> c(n); for (auto &x : c) cin >> x;
    sort(ALL(c));
    int cs = 0;
    for (int i = 0; i < n; i++) {
        cs += c[i];
        if (cs > s) {cout << i; exit(0);} 
    }
    cout << n;
}