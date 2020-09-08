/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0905 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

auto x = "the quick brown fox jumps over the lazy dog";

map<char, char> dict;

bool check_key(const string &s) {
    if (s.length() != strlen(x)) return false;
    dict = {{' ', ' '}};
    for (int i = 0; x[i]; i++) {
        if (dict.count(s[i]) && dict[s[i]] != x[i]) return false;
        dict[s[i]] = x[i];
    }
    return true;
}

int main() {
    int n; cin >> n;
    vector<string> dt; string s;
    for(getline(cin, s); n--;){
        getline(cin, s); dt.push_back(s);
    }
    bool f = false;
    for (auto &x: dt) {
        if (f |= check_key(x)) continue;
    }
    if (!f) {
        cout << "No solution";
        return 0;
    }
    for (auto &x: dt) {
        for (auto c: x) {
            cout << dict[c];
        }
        cout << endl;
    }
}