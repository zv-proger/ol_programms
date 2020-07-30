/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0369 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A>             void print(const A &a)                { cout << a << ' ';          }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...);     }
template <class... O>          void println(const O &...o)           { print(o...); cout << endl; }
template <class A>             void read(A &a)                       { cin >> a;                  }
template <class A, class... O> void read(A &a, O &...o)              { read(a); read(o...);       }
template <class... O>          void doans(const O &...o)             { println(o...); exit(0);    }

#define ti dt[i].f
#define si dt[i].s.s
#define pi dt[i].s.f

const int C1 = 102;
const int C2 = 30000;

int main() {
    int N, K, T, dp[C1][C2]; read(N, K, T);
    pair<int, pii> dt[100];
    for (int i = 0; i < N; i++) { read(ti); }
    for (int i = 0; i < N; i++) { read(pi); }
    for (int i = 0; i < N; i++) { read(si); }
    sort(dt, dt + N);
    for (int i = 0; i < C1; i++) {
        for (int j = 0; j < C2; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    int i = 0; while (ti == 0) i++;
    for (int t = 1; t <= T; t++) {
        for (int i = 1; i <= K; i++) {
            dp[i][t] = max(dp[i-1][t-1], max(dp[i][t-1], dp[i+1][t-1]));
        }
        while (ti == t) {
            if (dp[si][t] >= 0) {
                dp[si][t] += pi;
            }
            i++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= K; i++) {
        ans = max(ans, dp[i][T]);
    }
    doans(ans);
}