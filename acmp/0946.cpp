/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0946 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

/*
    ������ �� ��� (1 ��� 2) ����������, ��� ���� �������� � ������ ���� ��� � ������� ����
    ��������������. ������ ����� ����� (�� 0 �� 10000) ���������� ����� �����. ��������
    ������ ����� � ����� ����������� ����� ������ 3 ��� 4, ������������ � ������ � �������
    ���� ����� �������������� ��������� ����.
*/

list<int> dt;

void request() {
    int i, x; cin >> i;
    switch (i) {
        case 1: cin >> x; dt.push_front(x); break;
        case 2: cin >> x; dt.push_back(x); break;
        case 3: cout << dt.front() << ' '; dt.pop_front(); break;
        case 4: cout << dt.back() << ' '; dt.back(); break;
    }
}

int main() {
    int n; cin >> n;
    for (; n--;) request();
}