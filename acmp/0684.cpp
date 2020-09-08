/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0684 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

bool can(char a, char b, char c, char d) {
    if (abs(c - a) > d - b) return false;
    if ((a + b) % 2 != (c + d) % 2 ) return false;
    return true;
}

int main() {
    char a, b, c, d; cin >> a >> b >> c >> d;
    cout << (can(a,b,c,d) ? "YES" : "NO");
}