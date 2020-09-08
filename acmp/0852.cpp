/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0852 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<string> xx;
    bool op, in = false;
    string cur;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '<' && s[i+1] == '/') {
            if (in) return 0;
            op = false; in = true; i++; continue;
        }
        if (s[i] == '<') {
            if (in) return 0;
            op = true; in = true; continue;
        }
        if (s[i] == '>') {
            if (!in) return 0;
            if (op) xx.push(cur);
            else {
                if (xx.empty() || cur != xx.top()) {
                    return 0;
                }
                xx.pop();
            }
            cur = ""; in = false; continue;
        }
        if (islower(s[i])) {
            if (!in) return 0;
            cur += s[i]; continue;
        }
        return 0;
    }
    return xx.empty();
}

int main() {
    string s; cin >> s;
    for (int i = 0; s[i]; i++) {
        char bk = s[i];
        for (char c = 'a'; c <= 'z'; c++) {
            s[i] = c; if (check(s)) { cout << s; return 0; }
        }
        s[i] = '<'; if (check(s)) { cout << s; return 0; }
        s[i] = '/'; if (check(s)) { cout << s; return 0; }
        s[i] = '>'; if (check(s)) { cout << s; return 0; }
        s[i] = bk;
    }
}