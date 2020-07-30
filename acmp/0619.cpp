/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0619 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

void print(const double &d     { cout << setprecision(7) << d << ' ';                             }
template <class A>             void print(const A &a)                { cout << a << ' ';          }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...);     }
template <class... O>          void println(const O &...o)           { print(o...); cout << endl; }
template <class A>             void read(A &a)                       { cin >> a;                  }
template <class A, class... O> void read(A &a, O &...o)              { read(a); read(o...);       }
template <class... O>          void doans(const O &...o)             { println(o...); exit(0);    }

int main() {
    int n, q; read(n, q);
    double dp[2][3001] = {1}, *c = dp[0], *p = dp[1];
    for (; n--;){
        swap(c, p);
        for (int i = 1; i < 3001; i++) {
            c[i] = 0;
            for (int j = max(i-6, 0); j < i; j++){
                c[i] += p[j] / 6;
            }
        }
    }
    doans(p[q]);
}