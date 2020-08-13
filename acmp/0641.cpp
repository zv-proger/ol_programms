/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0641 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string ans = s.substr(2);
    for (int i = 0; s[i]; i++) {
        for (int j = i + 1; s[j]; j++) {
            ans = max(ans, s.substr(0, i) + s.substr(i + 1, j - i - 1) + s.substr(j + 1));
        }
    }
    cout << ans << endl;
}