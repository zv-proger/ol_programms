/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0371 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int dt[1000001];

void init() {
    set<int> simp;
    for (int i = 2; i * i <= 1e6; i++) {
        for (int j = i * i; j <= 1e6; j += i) {
            dt[j] += i;
            if (i * i != j) dt[j] += j / i;
        }
    }
    for (int i = 2; i <= 1e6; i++) {
        dt[i]++;
    }
}

int main() {
    init();
    int a, b; cin >> a >> b;
    bool f = true;
    for (int i = a; i <= b; i++) {
        if (dt[i] >= a && dt[i] <= b && i != dt[i] && dt[dt[i]] == i) {
            cout << i << ' ' << dt[i] << endl;
            dt[dt[i]] = f = false;
        }
    }
    if (f) cout << "Absent";
}