/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0950 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    char c = 'a';
    for (char t; cin >> t; ) {
        if (t == '1') {
            cout << c; c = 'a';
        }
        else
            c++;
    }
}