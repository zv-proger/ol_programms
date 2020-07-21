/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0330 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

using ll = long long;
using pll = pair<ll, ll>;

template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}

int main() {
    pll a, b; cin >> a >> b;
    a = a - b;
    if (a.f + a.s & 1) cout << 0;
    else cout << (a.f * a.f - a.s * a.s ? 2 : 1);
}