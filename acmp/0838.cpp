/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0838 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

/*
    'a' - 'z': �� ����� �������� ����� ����������� �������� ��������� ���������� �������, ������ ����� ���� �� ����������� ������ � �������� (����� ���������� � �������).
    'A' - 'Z': 10 + lower(x),
    �������: 4 ������ �������.
    '0' - '9': (13 � x),
    '.': 5 �������,
    ';': 7 �������,
    ',': 2 ������.
    [=+-'"]: 3 ������ �������.
    [()]: 1 ������
    [{[}]<>]: �� 8.
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