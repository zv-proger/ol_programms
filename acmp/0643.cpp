/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0643 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int count(int a) {
    int ans = 0;
    while (a) ans += a & 1, a >>= 1;
    return ans;
}

int main() {
    ll n; cin >> n;
    cout << n + count(n);
}