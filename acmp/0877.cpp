/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0877 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> dt;
    string s, nm; cin >> s >> nm;
    getline(cin, s);
    while(getline(cin, s)) {
        dt.push_back("");
        auto ss = istringstream(s);
        ss >> s; 
        getline(ss, dt.back());
    }
    dt.pop_back();
    for (auto &x: dt) {
        while (isspace(x.front())) x.erase(0, 1);
        while (isspace(x.back())) x.pop_back();
        if (!set<char>({'?','!','.'}).count(x.back())) x.push_back('.');
        if (x.back() == '.') x.back() = ',';
    }
    bool f = false;
    for (auto &x: dt)
        cout << '"' << x << "\" --- skazal " << ((f = !f) ? "Fedya": nm) << '.' << endl;
}