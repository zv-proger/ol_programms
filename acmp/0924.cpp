/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0924 с сайта acmp.ru
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

string a[4];

void check(char c) {
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (a[i][j] == c && a[i-1][j] == c && a[i][j-1] == c && a[i-1][j-1] == c) doans("No");
        }
    }
}

int main() {
    read(a[0], a[1], a[2], a[3]);
    check('B');
    check('W');
    doans("Yes");
}