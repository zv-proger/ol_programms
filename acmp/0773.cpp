/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0773 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A> void print(A a) { cout << a << ' '; }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

int main() {
    int a, b; cin >> a >> b;
    doans(a*a*b);
}