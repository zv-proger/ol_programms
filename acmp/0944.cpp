/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0944 � ����� acmp.ru
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
    vector<int> coins; read(coins);
    int n = 1001;
    bool dp[1001] = {1};
    for (int i = 0; i < n; i++) {
        if (dp[i]) {
            for (auto &c : coins) {
                if (i + c < n) {
                    dp[i + c] = true;
                }
            }
        }
    }
    read(n);
    while(n--) {
        int t; read(t);
        print(dp[t]);
    }
}