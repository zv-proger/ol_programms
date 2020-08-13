/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0520 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using piii = pair<pair<ll, ll>, ll>;

ll cost(piii a) {
    return a.first.first * 105 + a.first.second * 1025 + a.second * 11400;
}

int main() {
    int n; cin >> n;
    piii f = {{n % 12, n / 12 % 12}, n / 144}, s = {{0, n / 12 % 12 + 1}, n / 144}, t = {{0, 0}, n / 144 + 1};
    if (cost(f) > cost(s)) f = s;
    if (cost(f) > cost(t)) f = t;
    cout << f.second << ' ' << f.first.second << ' ' << f.first.first;
}