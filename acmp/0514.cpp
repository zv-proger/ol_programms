/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0514 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; ; i++) {
        int n = i + 1;
        if (n*(n+1)/2 > t) {
            cout << i;
            return 0;
        }
    }
}