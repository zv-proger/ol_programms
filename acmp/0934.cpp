/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0934 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;


string srt(string s) { sort(s.begin(), s.end()); return s; }

int main() {
    int n; cin >> n;
    // Считываю массив строк в группы dt
    map<string, multiset<string>> dt;
    for (; n--;) {
        string a; cin >> a;
        dt[srt(a)].insert(a);
    }
    // Заполняю массив для сортировки групп sub
    vector<pair<int, set<string>>> sub;
    for (auto &p: dt) {
        sub.push_back({-p.second.size(), {p.second.begin(), p.second.end()}});
    }
    sort(sub.begin(), sub.end());
    // Вывожу результат
    for (int i = 0; i < min(5, (int)sub.size()); i++) {
        cout << "Group of size " << -sub[i].first << ": ";
        for (auto &s: sub[i].second) {
            cout << s << ' ';
        }
        cout << '.' << endl;
    }
}