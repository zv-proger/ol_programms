/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0791 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int i; cin >> i;
    i--;
    if (i >= 8) { cout << i - 8 + 1 << ' '; }
    if (i % 8) { cout << i << ' '; }
    if ((i + 1) % 8) { cout << i + 2 << ' '; }
    if (i + 8 < 64) { cout << i + 8 + 1 << ' '; }
}