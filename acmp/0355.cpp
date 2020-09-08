/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0355 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
    while (next_permutation(s.begin(), s.end()))
        cout << s << endl;
}