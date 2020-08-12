/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0419 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

string s;

bool is_pal(int l, int r) {
    while(l < r) {
        while (!isalpha(s[l]) && l < r) l++;
        while (!isalpha(s[r]) && l < r) r--;
        if (l >= r) break;
        if (tolower(s[l]) != tolower(s[r])) {
            return false;
        }
        l++, r--;
    }
    return true;
}

int main() {
    getline(cin, s);
    int l = 0, r = s.length() - 1;
    while(l < r) {
        while (!isalpha(s[l]) && l < r) l++;
        while (!isalpha(s[r]) && l < r) r--;
        if (l >= r) break;
        if (tolower(s[l]) != tolower(s[r])) {
            if (is_pal(l + 1, r - 1)) {
                s[l] = s[r]; break;
            }
            if (is_pal(l + 1, r)) {
                s[l] = 1; break;
            }
            if (is_pal(l, r - 1)) {
                s[r] = 1; break;
            }
            cout << "NO"; return 0;
        }
        l++, r--;
    }
    cout << "YES" << endl;
    for (char c: s) { if (c > 1) cout << c; }
}