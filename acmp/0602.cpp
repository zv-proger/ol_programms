/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0602 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; 
    vector<int> dt(n); 
    for (auto &x: dt) cin >> x;
    sort(dt.begin(), dt.end());
    int ans = 1;
    for (int i = 2; i < n; i++) {
        if (dt[ans] - dt[ans - 1] > dt[i] - dt[i - 1])
            ans = i;
    }
    cout << dt[ans - 1] << ' ' << dt[ans];
}