/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0576 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = n, s = n;
    for (int i = 2; i <= n; i++) {
        if (s % i == 0) ans -= ans / i;
        while (s % i == 0) s /= i;
    }
    cout << min(ans, n - 1);
}