/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0997 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

/*
    � ��������� M ������� ��������� ����� ���������. ����� ������� �� ��������� � �������� ���������� ����,
    �������� � ������ ����������: ����� (.), ������� (,), ��������� (:), ����� � �������� (;), ���� (-),
    ���������� ('), ������� ("), ��������������� (!) � �������������� (?) ������.
*/

void do_ans(const char* msg) {
    cout << msg; exit(0);
}

int main() {
    int n, m; cin >> n >> m;
    string s;
    set<string> a, b;
    for (; n--;) {
        cin >> s;
        a.insert(s);
    }
    getline(cin, s);
    for (; m--;) {
        getline(cin, s);
        for (auto &c: s) {
            c = tolower(c);
            if (set<char>({'.',',',':',';','-','\'','"','!','?'}).count(c))
                c = ' ';
        }
        istringstream ss(s);
        while (ss >> s) {
            b.insert(s);
        }
    }
    for (auto &s: b) {
        if (!a.count(s)) do_ans("Some words from the text are unknown.");
        a.erase(s);
    }
    if (!a.empty()) do_ans("The usage of the vocabulary is not perfect.");
    do_ans("Everything is going to be OK.");
}