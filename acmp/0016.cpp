/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0016 с сайта acmp.ru
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ans(int a, int p) {
    int res = 0;
    if (a < p) res = 1;
    for(int i = 1; i < min(a, p); i++)
        res += ans(a - i, i);
    return res;
}

int main() 
{
    int a;
    cin >> a;
    cout << ans(a, a + 1);
}