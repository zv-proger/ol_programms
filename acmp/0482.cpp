/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0482 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    stringstream ss;
    int k = 1, n; cin >> n;
    char c;
    for ( ; n--;) {
        if (!(ss >> c)) {
            ss.clear();
            for (int i = 1; i <= k; i++) {
                ss << i;
            }
            k++;
            ss >> c;
        }
    }
    cout << c;
}