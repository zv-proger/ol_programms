/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0194 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    if (n == 1 || n == 2) { cout << 1; return 0; }
    int c = 2, p = 1, pp = 1;
    for (n -= 3; n--;) {
        swap(p, pp);
        swap(c, p);
        c += p + 1;
    }
    cout << c << endl;
}