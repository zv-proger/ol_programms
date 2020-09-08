/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0667 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template <class A>             void print(const A &a)                { cout << a << ' ';          }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...);     }
template <class... O>          void println(const O &...o)           { print(o...); cout << endl; }
template <class A>             void read(A &a)                       { cin >> a;                  }
template <class A, class... O> void read(A &a, O &...o)              { read(a); read(o...);       }
template <class... O>          void doans(const O &...o)             { println(o...); exit(0);    }

int main() {
    ll a, b, c, d; read(a, b, c, d);
    if (a*b*c - a*b - a*c - b*c <= 0) doans(-1);
    if (a*b*c*d % (a*b*c - a*b - a*c - b*c) != 0) doans(-1);
    ll n = a*b*c*d / (a*b*c - a*b - a*c - b*c);
    if (n % a != 0) doans(-1);
    if (n % b != 0) doans(-1);
    if (n % c != 0) doans(-1);
    doans(n);
}