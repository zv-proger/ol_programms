/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0633 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    string a[3], c; 
    getline(cin, c);
    getline(cin, a[0]);
    getline(cin, a[1]);
    getline(cin, a[2]);
    sort(a, a + 3);
    cout << c << ": " << a[0] << ", " << a[1] << ", " << a[2];
}