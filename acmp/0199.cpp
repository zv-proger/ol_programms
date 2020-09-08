/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0199 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<int, string> alpha = {
    {-1, "I"},
    {-4, "IV"},   {-5, "V"},
    {-9, "IX"},   {-10, "X"},
    {-40, "XL"},  {-49, "IL"},  {-50, "L"},
    {-90, "XC"},  {-99, "IC"},  {-100, "C"},
    {-400, "CD"}, {-499, "ID"}, {-500, "D"},
    {-900, "CM"}, {-999, "IM"}, {-1000, "M"},
};

string to_roman(int x) {
    string ans;
    while (x) {
        for (auto &p: alpha) {
            if (x + p.first >= 0) {
                ans += p.second;
                x += p.first;
                break;
            }
        }
    }
    return ans;
}

map<string, int> from;

int gcd(int a, int b) { return b ? gcd(b, a % b): a; }

void err() {
    cout << "ERROR";
    exit(0);
}

int main() {
    for (int i = 1; i < 1000; i++) {
        from[to_roman(i)] = i;
    }
    string as, bs;
    if (!getline(cin, as, '/')) err();
    if (!getline(cin, bs)) err();
    if (!from.count(as)) err();
    if (!from.count(bs)) err();
    int a = from[as], b = from[bs], c = gcd(a, b);
    a /= c; b /= c;
    cout << to_roman(a);
    if (b > 1) cout << '/' << to_roman(b);
}