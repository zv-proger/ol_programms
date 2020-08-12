/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0519 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n; cin >> n;
    vector<int> digits;
    for(; n; n /= 10) digits.push_back(n % 10);
    sort(ALL(digits));
    for (int i = 0; ; i++) {
        if (digits[i]) {
            swap(digits[0], digits[i]);
            break;
        }
    }
    for (auto x: digits) cout << x;
    cout << ' ';
    sort(ALL(digits), greater<int>());
    for (auto x: digits) cout << x;
}