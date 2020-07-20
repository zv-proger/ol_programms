/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0037 с сайта acmp.ru
*/
     
#include<bits/stdc++.h>
using namespace std;
 
const double eps = 1e-15;
 
using ll = long long;
 
template <class A> void doans(A a) { cout << a << ' '; exit(0); }
template <class A, class... O> void doans(A a, O... o) { cout << a << ' '; doans(o...); }
 
double f() {
    int x, y; cin >> x >> y;
    return sqrt(x*x + y*y);
}
 
int main() {
    int t; double p; cin >> t >> p;
    for(;t--;) {
        double pred = f(), post = f();
        if (pred < eps && post < eps) continue;
        if (pred > eps && post < eps) continue;
        if (pred < eps && post > eps) doans("No");
        if (post / pred > p + eps) doans("No");
    }
    doans("Yes");
}