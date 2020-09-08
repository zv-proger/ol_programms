/*
    јвтор кода: ¬адим «инов (zv.proger@yandex.ru)
    –ешение задачи 0997 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

/*
    ¬ следующих M строках находитс€ текст сочинени€. “екст состоит из заглавных и строчных английских букв,
    пробелов и знаков препинани€: точек (.), зап€тых (,), двоеточий (:), точек с зап€тыми (;), тире (-),
    апострофов ('), кавычек ("), восклицательных (!) и вопросительных (?) знаков.
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