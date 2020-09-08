/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0851 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

typedef string (*ft)(int, int);

string f(string s, int &a, int &b, int da, int db) {
    string ans;
    while(a + da >= 0 && b + db >= 0) {
        ans += s;
        a += da; b += db;
    }
    return ans;
}

string f1(int a, int b) {
    string ans = f("BG", a, b, -1, -1);
    while(a--) {
        ans += 'B';
    }
    while(b--) {
        ans += 'G';
    }
    return ans;
}

string f2(int a, int b) {
    string ans = f("GB", a, b, -1, -1);
    while(a--) {
        ans += 'B';
    }
    while(b--) {
        ans += 'G';
    }
    return ans;
}

string f3(int a, int b) {
    string ans = f("BGG", a, b, -1, -2);
    while(a--) {
        ans += 'B';
    }
    while(b--) {
        ans += 'G';
    }
    return ans;
}

string f4(int a, int b) {
    string ans = f("GBG", a, b, -1, -2);
    while(a--) {
        ans += 'B';
    }
    while(b--) {
        ans += 'G';
    }
    return ans;
}

string f5(int a, int b) {
    string ans = f("GGB", a, b, -1, -2);
    while(a--) {
        ans += 'B';
    }
    while(b--) {
        ans += 'G';
    }
    return ans;
}

string f6(int a, int b) {
    string ans = f("BG", a, b, -1, -1);
    while(b--) {
        ans += 'G';
    }
    while(a--) {
        ans += 'B';
    }
    return ans;
}

string f7(int a, int b) {
    string ans = f("GB", a, b, -1, -1);
    while(b--) {
        ans += 'G';
    }
    while(a--) {
        ans += 'B';
    }
    return ans;
}

string f8(int a, int b) {
    string ans = f("BGG", a, b, -1, -2);
    while(b--) {
        ans += 'G';
    }
    while(a--) {
        ans += 'B';
    }
    return ans;
}

string f9(int a, int b) {
    string ans = f("GBG", a, b, -1, -2);
    while(b--) {
        ans += 'G';
    }
    while(a--) {
        ans += 'B';
    }
    return ans;
}

string f10(int a, int b) {
    string ans = f("GGB", a, b, -1, -2);
    while(b--) {
        ans += 'G';
    }
    while(a--) {
        ans += 'B';
    }
    return ans;
}

ft funcs[] = {f1, f2, f3, f4, f5, f6, f7, f8, f9, f10};

bool cnt(string a) {
    a = a.back() + a + a.front();
    int ans = 0;
    for (int i = 1; a[i+1]; i++) {
        if (a[i] == 'G') ans += a[i-1] != a[i+1];
        else ans += a[i-1] == 'G' && a[i+1] == 'G';
    }
    return ans;
}

int main() {
    int n, m; cin >> n >> m;
    string ans = "BBB";
    for (auto &x: funcs) {
        if (cnt(ans) < cnt(x(n, m)))
            ans = x(n, m);
    }
    cout << ans;
}