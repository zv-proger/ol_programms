/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0485 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int n, k;

bool step(int c) {
    int x = n;
    while (x--) {
        if ((c % n) != k) return false;
        if ((c / n) == 0) return false;
        c -= k + c / n;
    }
    return true;
}

int main() {
    cin >> n >> k;
    int i = n;
    for (; true; i++) {
        if (step(i)) break;
    }
    cout << i;
}