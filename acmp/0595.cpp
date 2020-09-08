/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0595 с сайта acmp.ru
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


int main() {
    char aa[100001], bb[100001], *b = bb, *a = aa;
    cin >> a >> b;
    bool f = 0;
    int n = strlen(a); 
    if (n != strlen(b)) doans("No"); 
    rep:
    int i, ans;
    for (i = 0; a[i]; i++) {
        if (a[i] != b[i]) {
            a += i + 1; goto rep;
        }
    }
    ans = i;
    for (;b[i]; i++) {
        a--;
        if(b[i]!=*a) { 
            if (f) { doans("No"); }
            f = true;
            a = bb; b = aa;
            goto rep;
        }
    }
    doans("Yes\n", n - ans);
}