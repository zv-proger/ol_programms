/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0418 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    list<string> dt = {""};
    auto cur_row = dt.begin();
    size_t ans = 0;
    string s; getline(cin, s);
    for (auto c: s) {
        switch(c) {
            case '\\':
                dt.insert(++cur_row, "");
                cur_row--;
                break;
            case '<':
                if (cur_row -> empty()) {
                    if (dt.begin() == cur_row) break;
                    auto p = cur_row; p--;
                    dt.erase(cur_row);
                    cur_row = p;
                } else {
                    cur_row -> pop_back();
                }
                break;
            case '|':
                if (cur_row != --dt.end()) cur_row++;
                break;
            case '^':
                if (cur_row != dt.begin()) cur_row--;
                break;
            default:
                cur_row -> push_back(c);
                break;
        }
        ans = max(ans, cur_row -> size());
    }
    cout << ans;
}