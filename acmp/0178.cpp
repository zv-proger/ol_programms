/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0178 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}


int main() {
    vector<int> d; cin >> d;
    map<int, int> c;
    for (auto &x : d) { c[x]++; }
    int mx = 0;
    for (auto &p : c) { if (c[mx] < p.second) mx = p.first; }
    for(int i = 0, j = 0; j < d.size(); i++, j++) {
        swap(d[i], d[j]);
        if (d[i] == mx) {
            i--;
        }
    }
    cout << d << endl;
}