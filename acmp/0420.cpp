/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0420 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

bool check(string s) {
    reverse(ALL(s));
    string prev = "Oa", cur;
    while (!s.empty()) {
        if (!isupper(s.back())) return false;
        cur = s.back(); s.pop_back();
        if (!s.empty() && islower(s.back())) { cur += s.back(); s.pop_back(); }
        if (cur == prev) return false;
        if (s.empty()) break;
        if (!s.empty() && isdigit(s.back())) {
            int cnt = 0;
            while (!s.empty() && isdigit(s.back())) {
                cnt = cnt * 10 + s.back() - '0';
                s.pop_back();
            }
            if (cnt < 2) return false;
        }
        prev = cur;
    }
    return true;
}

int main() {
    string s; cin >> s;
    cout << (check(s)? "YES": "NO");
}