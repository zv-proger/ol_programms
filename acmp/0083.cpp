/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0083 с сайта acmp.ru
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
    int n, m; read(n, m);
    if (n > m) swap(n, m);
    vector<vector<bool>> can(1 << n, vector<bool>(1 << n, 1));
    for (int i = 0; i < (1 << n); i++) {
        for (int j = i; j < (1 << n); j++) {
            int a = i & j, b = ~i & ~j;
            for (int k = 3; k < (1 << n); k <<= 1) {
                if ((k & a) == k || (k & b) == k) {
                    can[i][j] = can[j][i] = 0;
                    break;
                }
            }
        }
    }
    vector<vector<int>> dp(m, vector<int>(1 << n, 1));
    int ans = 1 << n;
    for (int i = 1; i < m; i++) {
        ans = 0;
        for (int c = 0; c < (1 << n); c++) {
            dp[i][c] = 0;
            for (int p = 0; p < (1 << n); p++) {
                dp[i][c] += dp[i-1][p] * can[p][c];
            }
            ans += dp[i][c];
        }
    }
    doans(ans);
}