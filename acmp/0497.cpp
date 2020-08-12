/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0497 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

string mx, mn;
string cur;
int n;

vector<int> plc = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void updateMX() {
    mx = cur;
}

void updateMN() {
    mn = cur;
}

void stepMX (int i, int k, int l = 9) {
    if (k < 0 || i * 7 < k || k < i * 2) return;
    if (i == 0 && k == 0) updateMX();
    if (i == 0) return;
    for (; l >= 0; l--) {
        cur.push_back('0' + l);
        stepMX(i - 1, k - plc[l], l);
        cur.pop_back();
        if (mx != "") return;
    }
}

void stepMN (int i, int k, int l = 0) {
    if (mn != "") return;
    if (k < 0 || i * 7 < k || k < i * 2) return;
    if (i == 0 && k == 0) updateMN();
    if (i == 0) return;
    for (; l < 10; l++) {
        cur.push_back('0' + l);
        stepMN(i - 1, k - plc[l], l);
        cur.pop_back();
        if (mn != "") return;
    }
}

int main() {
    int n, k; cin >> n >> k;
    stepMX(n, k, 9);
    cur = "1";
    stepMN(n - 1, k - 2);
    cur = "2";
    stepMN(n - 1, k - 5);
    cur = "4";
    stepMN(n - 1, k - 4);
    cur = "6";
    stepMN(n - 1, k - 6);
    cur = "7";
    stepMN(n - 1, k - 3);
    cur = "8";
    stepMN(n - 1, k - 7);
    if (mx == "") cout << "NO SOLUTION";
    else cout << mn << endl << mx;
}