/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0906 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, ll> csh;

int hsh(int a, int b, int c) {
    return a + b * 31 + c * 961;
}

/*
    если a ? 0 или b ? 0 или c ? 0, то F(a, b, c) = 1
    если a > 20 или b > 20 или c > 20, то F(a, b, c) = F(20, 20, 20)
    если a < b и b < c, то F(a, b, c) = F(a, b, c-1) + F(a, b-1, c-1) - F(a, b-1, c)
    иначе F(a, b, c) = F(a-1, b, c) + F(a-1, b-1, c) + F(a-1, b, c-1) - F(a-1, b-1, c-1)
*/

ll f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return f(20, 20, 20);
    if (csh.count(hsh(a, b, c))) return csh[hsh(a, b, c)];
    if (a < b && b < c) return csh[hsh(a, b, c)] = f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c);
    return csh[hsh(a, b, c)] = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
}

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << f(a, b, c);
}