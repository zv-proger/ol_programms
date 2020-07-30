/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0687 с сайта acmp.ru
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
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}
template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}

int main() {
    int pr[12][102], dp[12][102], n, m;
    read(n, m);

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            read(dp[i][j]);
        }
    }
    for (int j = 2; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int p = i-1;
            if (dp[p][j-1] > dp[i][j-1]) p = i;
            if (dp[p][j-1] > dp[i+1][j-1]) p = i+1;
            pr[i][j] = p;
            dp[i][j] += dp[p][j-1];
        }
    }
    int best = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[best][m] > dp[i][m]) best = i;
    }
    vector<int> ans;
    int cur = best;
    for (int j = m; j; j--) {
        ans.push_back(cur);
        cur = pr[cur][j];
    }
    reverse(ALL(ans));
    doans(ans, '\n', dp[best][m]);
}