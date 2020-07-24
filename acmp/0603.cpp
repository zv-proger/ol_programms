/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0603 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    getline(cin, t);
    for (char &c : t) { c = tolower(c); }
    while(isspace(t.back()))
        t.pop_back();
    while(isspace(t.front()))
        t.erase(0, 1);
    getline(cin, s, '\0');
    vector<int> ind, todel;
    for (int i = 0; s[i]; i++) {
        ind.push_back(i);
        if (i && isspace(s[i]) && isspace(s[i - 1]))
            todel.push_back(i);
    }
    string r = s;
    int l = 0;
    for (int i = 0, j = 0; r[i]; i++, l++) {
        r[l] = tolower(r[i]);
        if (isspace(r[l])) r[l] = ' ';
        ind[l] = ind[i];
        if (j < todel.size() && i == todel[j]) {
            l--; j++;
        }
    }
    ind.resize(l); r.resize(l);

    vector<int> toins;

    for (int i = 0; r[i + t.length() - 1]; i++) {
        for (int j = 0; t[j]; j++) {
            if (r[i + j] != t[j]) {
                goto next;
            }
        }
        toins.push_back(ind[i]);
next:;
    }
    while (!toins.empty()) {
        s.insert(toins.back(), 1, '@');
        toins.pop_back();
    }
    cout << s;
}