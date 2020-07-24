/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0719 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) x.begin(), x.end()


template <class A> void print(A a) { cout << a << ' '; }
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

int main() {
    string s; cin >> s;
    int zc = 0;
    while (s.back() == '0') {
        s.pop_back();
        zc++;
    }
    reverse(ALL(s));
    ll last = 0;
    for (int i = min(8, s.length()); i--) {
        last = last * 10 + s[i] - '0';
    }
    print (zc, last);
}