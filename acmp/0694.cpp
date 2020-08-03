/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0694 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> days(32, 1);
    int n; cin >> n;
    for (; n--;) {
        int a, b; cin >> a >> b;
        for (int i = 0; i <= 31; i++) {
            if (i < a || i > b) days[i] = 0; 
        }
    }
    bool f = 0;
    for (auto x : days) f |= x;
    if (f) cout << "YES";
    else cout << "NO";
}