/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0693 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    string a, b; cin >> a >> b;
    for (char &c: a) c = tolower(c);
    for (char &c: b) c = tolower(c);
    sort(ALL(a)); sort(ALL(b));
    cout << (a == b ? "Yes" : "No");
}