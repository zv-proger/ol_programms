/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0482 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    stringstream ss;
    int k = 1, n; cin >> n;
    char c;
    for ( ; n--;) {
        if (!(ss >> c)) {
            ss.clear();
            for (int i = 1; i <= k; i++) {
                ss << i;
            }
            k++;
            ss >> c;
        }
    }
    cout << c;
}