/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0786 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int i = 1;
    while (i <= n) i *= 2;
    cout << n - i / 2;
}