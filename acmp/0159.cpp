/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0159 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

template <class A> ostream &operator <<(ostream &o, const vector<A> &a) { for (auto &x : a) o << x << ' '; return o; }
template <class A> void print(A a) { cout << a << ' '; }

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n); for(auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) { b[a[i] - 1] = i + 1; }
    print(b);
}