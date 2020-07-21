/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0348 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;

template <class A> void print(A a) { cout << a << ' '; }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}

int sign (const int &a) { return a > 0 ? 1 : a ? -1 : 0; }

struct seg {
    pii s, e;
    friend istream &operator >> (istream &a, seg &b) {return a >> b.s >> b.e;}
    int scoso(const pii &p) { ll coso = (e - s).f * (p - s).s - (e - s).s * (p - s).f; return sign(coso); }
    bool x_intersept(const seg &p) {
        pii a = minmax(s.f, e.f), b = minmax(p.s.f, p.e.f);
        if (a.f > b.f) swap(a, b);
        return a.s >= b.f;
    }
    bool y_intersept(const seg &p) {
        pii a = minmax(s.s, e.s), b = minmax(p.s.s, p.e.s);
        if (a.f > b.f) swap(a, b);
        return a.s >= b.f;
    }
};

int main() {
    seg a, b;
    cin >> a >> b;
    if (b.scoso(a.s) * b.scoso(a.e) > 0) doans("No");
    if (a.scoso(b.s) * a.scoso(b.e) > 0) doans("No");
    if (a.x_intersept(b) && a.y_intersept(b)) doans("Yes");
    doans("No");
}