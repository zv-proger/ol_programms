/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0785 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool f(int x) {
    int d = 10;
    while (d < x) d *= 10;
    return x == 1LL * x * x % d;
}

int main() {
    int a, b; cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (f(i)) cout << i << ' ';
    }
}