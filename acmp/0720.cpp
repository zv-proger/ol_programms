/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0720 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    double r, l; cin >> r >> l;
    r /= l;
    int ans = 0;
    for (int h = r - 1e-9; h; h--) {
        int d = sqrt(r * r - h * h) + 1e-9;
        if (h) ans += d;
    }
    cout << ans * 4;
}