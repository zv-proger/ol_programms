/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0796 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> dt;

int main() {
    int w, b; cin >> w >> b;
    string s;
    bool f = true;
    while (getline(cin, s)) {
        if (s == "") { f = true; continue; }
        if (f) dt.push_back(vector<string>());
        f = false;
        auto &cur = dt.back();
        bool x = true, p;
        for (auto &c: s) {
            if (isspace(c)) { x = true; continue; }
            if (x) cur.push_back("");
            p = string(",.?!-:’'").find(string() + c) != string::npos;
            if (p && x) cur.pop_back();
            x = p;
            cur.back() += c;
        }
    }
    for (auto &cur: dt) {
        int cw = b;
        for (int i = 0; i < b; i++) cout << ' ';
        bool f = 1;
        for (auto s: cur) {
            cw += !f + s.length();
            if (cw > w) cout << endl, cw = s.length(), f = 1;
            if (!f) cout << ' ';
            f = 0;
            cout << s;
        }
        cout << endl;
    }
}