/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0447 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 1;
    for (; n; n--) {
        ans *= n;
        while(ans % 10 == 0) ans /= 10;
        ans %= 10000;
    }
    cout << ans % 10;
}