/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0446 с сайта acmp.ru
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

map<int, set<char>> can = {
    {0, {'.'}},
    {1, {'B', '.'}},
    {2, {'G', '.'}},
    {3, {'G', 'B', '.'}},
    {4, {'R', '.'}},
    {5, {'R', 'B', '.'}},
    {6, {'R', 'G', '.'}},
    {7, {'R', 'G', 'B', '.'}}
};

int main() {
    int n, m; cin >> n >> m;
    vector<string> pic(n);
    for (auto &x: pic) read(x);    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c; cin >> c;
            if (!can[c].count(pic[i][j]))
                doans("NO");
        }
    }
    doans("YES");
}