/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0863 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

struct nd {
    nd *left, *right;
    int val;
    nd(int v) {
        left = right = 0;
        val = v;
    }
    void add(int a, int b) {
        if (b % 2 == 0) {
            if (!right) {
                right = new nd(a);
            } else {
                right -> add(a, (b - 1) / 2);
            }
        } else {
            if (!left) {
                left = new nd(a);
            } else {
                left -> add(a, b / 2);
            }
        }
    }
    void print() {
        if (left) left -> print();
        cout << val << ' ';
        if (right) right -> print();
    }
};

int main() {
    int n; cin >> n;
    nd root(0);
    for (int i = 1; i < n; i++) {
        root.add(i, i);
    }
    root.print();
}