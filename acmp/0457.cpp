/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0457 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int next(int a) {
    vector<int> v = {a % 10, a / 10 % 10, a / 100 % 10, a / 1000};
    sort(ALL(v));
    int g = v[3] * 1000 + v[2] * 100 + v[1] * 10 + v[0];
    int l = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
    return g - l;
}

int main() {
    int a; cin >> a;
    int c = 0;
    while (a != next(a)) {
        a = next(a);
        c++;
    }
    cout << a << endl << c;
}