/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0202 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

void solve1(const string &str, const string &sub) {
    string c = sub + '#' + str;
    vector<int> z(c.length());
    for (int i = 1, l = 0, r = 0; c[i]; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (c[i + z[i]] == c[z[i]])
            z[i]++;
        if (i + z[i] >= r) {
            l = i; r = i + z[i];
        }
        if (z[i] == sub.length()) cout << i - 1 - sub.length() << ' ';
    }

}

void solve2(const string &str, const string &sub) {
    string c = sub + '#' + str;
    vector<int> p(c.length());
    for (int i = 1, j = 0; c[i]; i++) {
        while (j && c[i] != c[j]) j = p[j-1];
        if (c[i] == c[j]) p[i] = ++j;
        if (p[i] == sub.length()) cout << i - 2 * sub.length() << ' ';
    }
}

void solve3(const string &str, const string &sub) {
    int s = 307, q = 1, sb = 0;
    vector<int> h(str.size() + 1);
    for (int i = 0; str[i]; i++) {
        h[i + 1] = h[i] + str[i] * q;
        q *= s;
    }
    q = 1;
    for (int i = 0; sub[i]; i++) {
        sb = sb + sub[i] * q;
        q *= s;
    }
    for (int i = 0; i + sub.length() <= str.length(); i++) {
        if (sb + h[i] == h[i + sub.length()]) {
            cout << i << ' ';
        }
        sb *= s;
    }
}

int main() {
    string a, b; cin >> a >> b;
    srand(time(0));
    switch(rand() % 3) {
        case 0: solve1(a, b); break;
        case 1: solve2(a, b); break;
        default: solve3(a, b);
    }
}