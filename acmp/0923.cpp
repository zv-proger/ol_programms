/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0923 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A> void print(A a) { cout << a << ' '; }
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}
template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

map<ll, ll> ch;

ll calc(ll n) {
    if (n == 3)
        return 1;
    if (n < 3)
        return 0;
    if (ch.count(n))
        return ch[n];
    if (n % 2)
        return ch[n] = calc(n / 2) + calc(n / 2 + 1);
    return ch[n] = 2 * calc(n / 2);
}

int main() {
    ll n; read(n);
    doans(calc(n));
}