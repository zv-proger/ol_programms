/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0823 с сайта acmp.ru
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
    int n, dp[4][51] = {0}, *prev = dp[0], *cur = dp[1], *f = dp[2], *l = dp[3]; read(n);
    for (int i = 1; i<= 50; i++) {
        f[i] = inf;
        cur[i] = i - 2;
    }
    for (;n--;) {
        int x, y; read(x, y);
        f[y] = min(f[y], x);
        l[y] = max(l[y], x);
    }
    int ans;
    for (int y = 1; y <= 50; y++) {
        swap(cur, prev);
        for (int x = 1; x <= 50; x++) {
            cur[x] = prev[x] + 1;
        }
        if (f[y] > l[y])
            continue;
        ans = inf;
        for (int x = 1; x <= 50; x++) {
            if (x < f[y]) cur[x] = prev[l[y]] + l[y] - x + 1;
            else if (x > l[y]) cur[x] = prev[f[y]] + x - f[y] + 1;
            else cur[x] = min (prev[f[y]] + 1 + 2 * l[y] - f[y] - x, prev[l[y]] + 1 + l[y] - 2 * f[y] + x);
            ans = min(ans, cur[x]);
        }
    }
    doans(ans);
}