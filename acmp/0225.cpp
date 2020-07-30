/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0225 с сайта acmp.ru
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
    int dt[5000][3], n; read(n);
    for (int i = 1; i <= n; i++) {
        read(dt[i][0], dt[i][1], dt[i][2]);
    }
    int dp[5000] = {0};
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + dt[i][0];
        if (i > 1) dp[i] = min(dp[i], dp[i-2] + dt[i-1][1]);
        if (i > 2) dp[i] = min(dp[i], dp[i-3] + dt[i-2][2]);
    }
    doans(dp[n]);
}