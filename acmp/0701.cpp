/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0701 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; string v; cin >> n >> v;
    n = (n % 10) + 2;
    int ans = 0;
    for (int i = 0; v[i]; i++) {
        ans = ans * n + (v[i] >= '0' && v[i] <= '9'? v[i] - '0': v[i] + 10 - 'A');
    }
    cout << ans;
}