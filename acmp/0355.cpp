/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0355 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
    while (next_permutation(s.begin(), s.end()))
        cout << s << endl;
}