/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0822 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;
using pff = pair<double, double>;
using pll = pair<long long, long long>;

template <class A, class B> pair<A, B> operator + (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f + b.f, a.s + b.s);}
template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}

int main() {
    pll d[3]; cin >> d[0] >> d[1] >> d[2];
    ll s = (d[1].s + d[0].s) * (d[1].f - d[0].f);
    s += (d[2].s + d[1].s) * (d[2].f - d[1].f);
    s += (d[0].s + d[2].s) * (d[0].f - d[2].f);
    s = abs(s);
    cout << fixed << s / 2.0;
}