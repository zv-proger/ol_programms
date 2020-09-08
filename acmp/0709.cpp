/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 709 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

string e;
map<char, bool> dt;

bool calc(const string &s);

bool calc_or(const string &s) {
    int st = 0, l = 0, r = s.length();
    bool f = false;
    for (int i = 0; i < r; i++) {
        char c = s[i];
        switch (c){
          case '(': st++; break;
          case ')': st--; break;
          case ',':
            if (st) continue;
            f |= calc(s.substr(l, i - l));
            l = i + 1;
        }
    }
    return f | calc(s.substr(l, r - l));
}

bool calc_and(const string &s) {
    int st = 0, l = 0, r = s.length();
    bool f = true;
    for (int i = 0; i < r; i++) {
        char c = s[i];
        switch (c){
          case '(': st++; break;
          case ')': st--; break;
          case ',':
            if (st) continue;
            f &= calc(s.substr(l, i - l));
            l = i + 1;
        }
    }
    return f & calc(s.substr(l, r - l));
}


bool calc_not(const string &s) {
    return !calc(s);
}

bool calc(const string &e) {
    if (e.length() == 1) return dt[e[0]];
    switch (e[0]) {
        case 'O': return calc_or(e.substr(3, e.length() - 4));
        case 'N': return calc_not(e.substr(4, e.length() - 5));
        case 'A': return calc_and(e.substr(4, e.length() - 5));
    }
    return 0;
}

int main() {
    cin >> e;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        dt.clear();
        for (int j = 0; j < k; j++) {
            string s; cin >> s;
            dt[s[0]] = s.find("TRUE") != string::npos;
        }
        cout << (calc(e) ? "TRUE" : "FALSE") << endl;
    }
}