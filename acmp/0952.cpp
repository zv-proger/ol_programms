/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0952 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if (!a && b) cout << "Impossible";
    else
        cout << max(0, b - a) + a << ' ' << a + b - !!b;
}