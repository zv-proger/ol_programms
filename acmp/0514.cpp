/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0514 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; ; i++) {
        int n = i + 1;
        if (n*(n+1)/2 > t) {
            cout << i;
            return 0;
        }
    }
}