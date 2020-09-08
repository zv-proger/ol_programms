/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0686 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n; cin >> n; 
    vector<int> dt(n);
    for (auto &x: dt) cin >> x;
    sort(ALL(dt));
    bool f = n & 1;
    list<int> a;
    while (!dt.empty()) {
        if (f) { a.push_front(dt.back()); } 
        else { a.push_back(dt.back()); }
        f = !f;
        dt.pop_back();
    }
    for (auto &x : a) cout << x << ' ';
}