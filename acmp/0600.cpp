/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0600 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool check(const string &s) {
    int z = 0, o = 0, t = 0;
    for (int i = 0; s[i]; i++) {
        switch(s[i]) {
          case '0':
            z++; if(o+t) return false; break;
          case '1':
            o++; if(t) return false; break;
          case '2':
            t++; break;
        }
    }
    return z == o && o == t;
}

int main() {
    int n; cin >> n;
    for (; n--;) {
        string s; cin >> s;
        cout << (check(s)? "YES": "NO") << endl;
    }
}