/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0574 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    string a, b; cin >> a >> b;
    sort(ALL(a)); sort(ALL(b));
    cout << (a == b ? "YES" : "NO");
}