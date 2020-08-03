/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0759 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for(auto &x : a) cin >> x;
    sort(ALL(a), greater<int>());
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, ans + a[i]);
    }
    cout << ans;
}