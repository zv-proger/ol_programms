/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0542 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n) {
        ans = ans * 2 + n % 2;
        n /= 2;
    }
    cout << ans;
}