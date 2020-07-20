/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0049 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<char, const set<char>> vars = {
    {'0', {0}}, {'1', {1}}, {'2', {2}}, {'3', {3}}, {'4', {4}},
    {'5', {5}}, {'6', {6}}, {'7', {7}}, {'8', {8}}, {'9', {9}},
    {'a', {0,1,2,3}}, {'b', {1,2,3,4}}, {'c', {2,3,4,5}},
    {'d', {3,4,5,6}}, {'e', {4,5,6,7}}, {'f', {5,6,7,8}},
    {'g', {6,7,8,9}}, {'?', {0,1,2,3,4,5,6,7,8,9}}
};

int operator^ (const set<char> &a, const set<char> &b){
    int ans = 0;
    for (char c : a) {
        if (b.count(c)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    string a, b; cin >> a >> b;
    int ans = 1;
    for (int i = 0; a[i]; i++)
        ans *= vars[a[i]] ^ vars[b[i]];
    cout << ans;
}