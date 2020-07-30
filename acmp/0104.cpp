/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0104 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool is_tmpl(const string &s) { for (char c : s) if (c == '?' || c == '*') return true; return false; }
#define doans(x) {cout << x << endl; exit(0);}

int main() {
    string wrd, tmpl; cin >> wrd >> tmpl;
    if (is_tmpl(wrd)) swap(wrd, tmpl);

    // dp init
    vector<int> tos = {0};

    // dp
    for (char c : tmpl) {
        if (tos.empty() || tos.front() == wrd.length() && c != '*') doans("NO");
        if (c == '*') {
            tos.resize(1);
            while(tos.back() != wrd.length()) {
                tos.push_back(tos.back() + 1);
            }
        } else if (c == '?') {
            for (auto &x: tos) {
                x++;
            }
            if (tos.back() > wrd.length()) {
                tos.pop_back();
            }
        } else {
            int i = 0, j = 0;
            for (; i < tos.size(); i++, j++) {
                swap(tos[i], tos[j]);
                if (wrd[tos[j]] == c) {
                    tos[j]++;
                } else {
                    j--;
                }
            }
            tos.resize(j);
        }
    }
    if (tos.empty() || tos.back() != wrd.size()) doans("NO");
    doans("YES");
}