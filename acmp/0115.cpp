/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0115 с сайта acmp.ru
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
    int dp[101][101] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            read(dp[i][j]);
            dp[i][j] += dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1];
        }
    }
    int ans = -inf;
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    ans = max(ans, dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][x2-1]);
                }
            }
        }
    }
    doans(ans);
}