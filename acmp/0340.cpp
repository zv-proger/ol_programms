/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0340 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

template <class A> void print(A a) { cout << a << ' '; }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

//Если коробки одинаковы, выведите "Boxes are equal".
//Если первая коробка может быть положена во вторую, выведите "The first box is smaller than the second one".
//Если вторая коробка может быть положена в первую, выведите "The first box is larger than the second one".
//Иначе, выведите "Boxes are incomparable".

struct box {
    int a, b, c;
    void norm() { if (a > b) swap(a, b); if (a > c) swap(a, c); if (b > c) swap(c, b);}
    void read() { cin >> a >> b >> c; norm(); }
};

int main() {
    box a, b;
    a.read(); b.read();
    if (a.a == b.a && a.b == b.b && a.c == b.c)
        doans("Boxes are equal");
    if (a.a >= b.a && a.b >= b.b && a.c >= b.c)
        doans("The first box is larger than the second one");
    if (a.a <= b.a && a.b <= b.b && a.c <= b.c)
        doans("The first box is smaller than the second one");
    doans("Boxes are incomparable");
}