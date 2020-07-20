/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0164 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

template <class A> void print(A a) { cout << a << ' '; }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

string s;

int norm(int a) {
    while (a >= 10){
        int b = 0;
        while (a) b += a % 10, a /= 10;
        a = b;
    }
    return a;
}

void check(int t) {
    int a = 0, b = 0;
    for (int i = 0; i < t; i++) {
        a += s[i] - '0';
    }
    for (int i = t; s[i]; i++) {
        b += s[i] - '0';
    }
    if (norm(a) == norm(b)) {
        doans("YES");
    }
}

int main() {
    cin >> s;
    if (s.length() > 1) for (int i = 1; s[i]; i++) {
        check(i);
    }
    doans("NO");
}