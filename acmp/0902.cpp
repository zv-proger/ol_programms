/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0902 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    int n; cin >> n;
    string s; cin >> s;
    reverse(ALL(s));
    string ans;
    for (int i = n; i--;) {
        ans += s[(1 << i) - 1] == 'O'? 'P': 'Z';
        int st = (1 << i) - 1, d = (1 << (i + 1));
        for (int j = st + d; j < s.size(); j += d) {
            if (s[j - d] == s[j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << ans;
}