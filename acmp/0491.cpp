/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0491 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

bool ispal(const string &s) {
    int l = 0, r = s.length() - 1;
    for (; l < r; l++, r--) {
        if (s[l] != s[r]) return false;
    }
    return true;
}

string calc(string a) {
    if (!ispal(a)) return a;
    a.pop_back();
    if (!ispal(a)) return a;
    return "NO SOLUTION";
}

int main() {
    string a; cin >> a;
    cout << calc(a);
}