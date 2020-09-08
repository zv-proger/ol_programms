/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0838 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

/*
    'a' - 'z': На набор строчной буквы английского алфавита требуется количество энергии, равное сумме цифр ее порядкового номера в алфавите (буквы нумеруются с единицы).
    'A' - 'Z': 10 + lower(x),
    «Пробел»: 4 джоуля энергии.
    '0' - '9': (13 – x),
    '.': 5 джоулей,
    ';': 7 джоулей,
    ',': 2 джоуля.
    [=+-'"]: 3 джоуля энергии.
    [()]: 1 джоулю
    [{[}]<>]: по 8.
*/

int cnt(char c) {
    if (isupper(c)) return cnt(tolower(c)) + 10;
    if (islower(c)) {
        int ans = 0, x = c - 'a' + 1;
        while (x) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    if (c == ' ') return 4;
    if (isdigit(c)) return 13 - (c - '0');
    if (c == '.') return 5;
    if (c == ';') return 7;
    if (c == ',') return 2;
    if (set<char>({'=', '+', '-', '\'', '"'}).count(c)) return 3;
    if (set<char>({'(', ')'}).count(c)) return 1;
    if (set<char>({'{', '}', '[', ']', '<', '>'}).count(c)) return 8;
    return 0;
}

int main() {
    char a[20001];
    int ans = 0;
    while(gets(a)) {
        for (int i = 0; a[i]; i++) {
            ans += cnt(a[i]);
        }
    }
    cout << ans;
}