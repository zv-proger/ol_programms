/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0950 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    char c = 'a';
    for (char t; cin >> t; ) {
        if (t == '1') {
            cout << c; c = 'a';
        }
        else
            c++;
    }
}