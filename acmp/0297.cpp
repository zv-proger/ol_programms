/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0297 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<char, int> cnt = {
    {'0', 1}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0},
    {'5', 0}, {'6', 1}, {'7', 0}, {'8', 2}, {'9', 1}
};

int main() {
    string s; cin >> s;
    int ans = 0;
    for (auto c : s) ans += cnt[c];
    cout << ans << endl;
}