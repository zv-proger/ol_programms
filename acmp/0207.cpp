/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0207 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using pii = pair<int, int>;
using pff = pair<double, double>;

template <class A, class B> pair<A, B> operator + (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f + b.f, a.s + b.s);}
template <class A, class B> pair<A, B> operator * (const pair<A, B>& a, const int b) {return pair<A, B>(a.f * b, a.s * b);}
template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}

const double w = sin(atan(1));

map<int, pff> d = {
    {1, {0, 1}},
    {2, {w, w}},
    {3, {1, 0}},
    {4, {w, -w}},
    {5, {0, -1}},
    {6, {-w, -w}},
    {7, {-1, 0}},
    {8, {-w, w}}
};

int main() {
    int n; cin >> n;
    pff c;
    for (;n--;) {
        int t, z;
        cin >> t >> z;
        c = c + d[t] * z;
    }
    cout << fixed << setprecision(3) << c << endl;
}