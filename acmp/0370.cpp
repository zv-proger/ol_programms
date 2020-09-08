/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0370 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

pii readPii() {
    int x, y; cin >> x >> y;
    return {x, y}; 
}

int main() {
    long long sm = 0;
    int n; cin >> n;
    pii s, pr = s = readPii(), cr;
    for(; --n;) {
        cr = readPii();
        sm += (cr.x - pr.x) * (cr.y + pr.y);
        swap(cr, pr);
    }
    sm += (s.x - pr.x) * (s.y + pr.y);
    cout << fixed << setprecision(1) << abs(sm) / 2.0;
}