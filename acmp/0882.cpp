/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0882 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using ll = long long;
using pii = pair<double, int>;


int main() {
    int n;
    double cur;
    cin >> n >> cur;
    vector<pair<pii, int>> dt(n);
    for (int i = 0; i < n; i++) {
        auto &x = dt[i].first;
        dt[i].second = i+1;
        cin >> x.first >> x.second;
    }
    sort(ALL(dt), [&] (pair<pii, int> f, pair<pii, int> s) {
        auto &x = f.first, &y = s.first;
        auto &a = x.first, &aa = y.first;
        auto &b = x.second, &bb = y.second;
        
        return - b * aa - bb >  - bb * a - b;
    });
    
    for (auto &p: dt) cout << p.second << endl;
}