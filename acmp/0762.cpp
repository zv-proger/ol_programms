/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0762 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n > 1) { ans++; n = n - 2 * n / 3; }
    cout << ans;
}