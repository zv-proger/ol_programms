/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0476 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

template <class A>             void print(const A &a)                { cout << a << ' ';          }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...);     }
template <class... O>          void println(const O &...o)           { print(o...); cout << endl; }
template <class A>             void read(A &a)                       { cin >> a;                  }
template <class A, class... O> void read(A &a, O &...o)              { read(a); read(o...);       }
template <class... O>          void doans(const O &...o)             { println(o...); exit(0);    }

int pl[250][250];

int main() {
    for (int i = 1; i < 250; i++) {
        pl[0][i] = pl[i][0] = pl[i][i] = 1;
    }
    for (int l = 3; l < 500; l++) {
        for (int i = 1; i < min(l, 250); i++) {
            int j = l - i;
            if (j >= 250 || pl[i][j]) continue;
            pl[i][j] = 2;
            for (int q = i; --q;)
                if (pl[q][j] == 2) { pl[i][j] = 1; continue; }
            for (int q = j; --q;)
                if (pl[i][q] == 2) { pl[i][j] = 1; continue; }
            for (int q = i, t = j; --q && --t;)
                if (pl[q][t] == 2) { pl[i][j] = 1; continue; }
        }
    }
    int n, m; read(n, m);
    doans(pl[n-1][m-1]);
}