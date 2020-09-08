/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0960 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A>             void print(const A &a)                { cout << a << ' ';          }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...);     }
template <class... O>          void println(const O &...o)           { print(o...); cout << endl; }
template <class A>             void read(A &a)                       { cin >> a;                  }
template <class A, class... O> void read(A &a, O &...o)              { read(a); read(o...);       }
template <class... O>          void doans(const O &...o)             { println(o...); exit(0);    }

int main() {
    ll a = 0, ab = 0, abc = 0;
    for (char c; cin >> c; ) {
        a += c == 'a';
        ab += a * (c == 'b');
        abc += ab * (c == 'c');
    }
    doans(abc);
}