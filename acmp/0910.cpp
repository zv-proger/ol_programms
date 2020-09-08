/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0910 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll cf = 1, cs = 1, ck = 0;
ll md;

ll next() {
    ck++;
    cf = cf * ck % md;
    cs = cs * 2 % md;
    return cf * cs % md;
}

int main() {
    ll sm = 0, n; cin >> n >> md;
    for (; n--;) {
        sm = (sm + next()) % md;
    }
    cout << sm;
}