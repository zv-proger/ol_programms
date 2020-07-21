/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0415 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

string calc (string a, string b) {
    string c = a + '#' + b;
    vector<int> p(c.size());
    int pos = -1;
    // prefix_func
    for (int i = 1, j = 0; i < c.length(); i++) {
        while (j != 0 && tolower(c[i]) != tolower(c[j])) j = p[j - 1];
        if (tolower(c[i]) == tolower(c[j])) p[i] = ++j;
        if (p[i] == a.length()) { pos = i - a.length() * 2; if(islower(b[pos])) break; }
    }
    if (pos >= 0) { b[pos] = toupper(b[pos]); return b; }
    return b.substr(0, b.length() - p.back()) + a;
}

int main() {
    string a, b; cin >> a >> b;
    string f = calc(b, a), s = calc(a, b);
    cout << min(make_pair(f.length(), f), make_pair(s.length(), s)).second << endl;
}