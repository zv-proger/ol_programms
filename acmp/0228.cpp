/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0228 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    double r = 100, d = 0, e = 0;
    int n; cin >> n; 
    for (; n--;) {
        double kd, ke; cin >> kd >> ke;
        double nr = max(r, max(d * kd, e * ke));
        double nd = max(d, max(r / kd, e * ke / kd));
        double ne = max(e, max(r / ke, d * kd / ke));
        r = nr; e = ne; d = nd;
    }
    cout << fixed << setprecision(3) << r;
}