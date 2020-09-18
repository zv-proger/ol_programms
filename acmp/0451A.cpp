/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0451A с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool ERR = false; // Сигнал об ошибке

bool check_bracket(const string &s);

bool is_num(const string &s);
bool is_dcr(const string &s);
bool is_fun(const string &s);
bool is_sum(const string &s);
bool is_mul(const string &s);

double calc_dcr(string s);
double calc_num(string s);
double calc_fun(string s);
double calc_mul(string s);
double calc_sum(string s);

double calc(string s);

string normolize(const string &s);

map<string, double (*)(double)> simple_funcs = {
    {"sin", sin}, {"cos", cos}
};

int main() {
    string s; getline(cin, s);
    double x = 0;
    if (check_bracket(s))
        x = calc(normolize(s));
    if (ERR) { cout << "Error" << endl;                       }
    else     { cout << fixed << setprecision(3) << x << endl; }
}

template <class T> void dbg_start(const char * name, const T &arg) {
#ifdef LCL
    cerr << "start \"" << name << "\" from ";
    cerr << "\"" << arg << "\"" << endl << endl;
#endif
}

template <class T> void dbg_end(const char * name, const T &res) {
#ifdef LCL
    //cerr << "end \"" << name << "\" with ";
    //cerr << "\"" << res << "\"" << endl << endl;
#endif
}

string trim(const string &s);

double calc(string s) {
    s = trim(s);
    if (s == "") goto err;

    if (is_dcr(s)) return calc_dcr(s);
    if (is_num(s)) return calc_num(s);
    if (is_fun(s)) return calc_fun(s);
    if (is_mul(s)) return calc_mul(s);
    if (is_sum(s)) return calc_sum(s);

err:
    ERR = true;
    return 0;
}

bool is_sum(const string &s) {
    int cnt = 0, st = 0;
    for (int i = 1; s[i]; i++) {
        char c = s[i];
        if (c == '(') { st++; continue; }
        if (c == ')') { st--; continue; }
        if (st) continue;
        if (c == '+' && s[i-1] != 'e') cnt++;
        if (c == '-' && s[i-1] != 'e') cnt++;
    }
    return cnt > 0;
}

bool is_mul(const string &s) {
    int cnt = 0, st = 0;
    for (int i = 1; s[i]; i++) {
        char c = s[i];
        if (c == '(') { st++; continue; }
        if (c == ')') { st--; continue; }
        if (st) continue;
        if (c == '+' && s[i-1] != 'e') return false;
        if (c == '-' && s[i-1] != 'e') return false;
        if (c == '*' || c == '/') cnt++;
    }
    return cnt > 0;
}

double calc_mul(string s) {
    dbg_start("calc_mul", s);
    int l = 0, st = 0;
    bool div = false;
    double res = 1;
    s += '*';
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(') { st++; continue; }
        if (c == ')') { st--; continue; }
        if (st) continue;
        if (c == '*' || c == '/') {
            res = (div ? res / calc(s.substr(l, i - l)) : res * calc(s.substr(l, i - l)));
            div = c == '/'; 
            l = i + 1;
        }
    }
    return res;
}


double calc_sum(string s) {
    dbg_start("calc_sum", s);
    int l = 0, st = 0;
    bool sub = false;
    double res = 0;
    s += '+';
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(') { st++; continue; }
        if (c == ')') { st--; continue; }
        if (st) continue;
        if ((c == '+' || c == '-') && s[i-1] != 'e') {
            res = (sub ? res - calc(s.substr(l, i - l)) : res + calc(s.substr(l, i - l)));
            sub = c == '-'; 
            l = i + 1;
        }
    }
    return res;
}

double calc_dcr(string s) {
    return calc(s.substr(1, s.length() - 2));
}

double calc_fun(string s) {
    dbg_start("calc_fun", s);

    for (auto &f: simple_funcs) {
        if (s.find(f.first) == 0 && is_dcr(s.substr(f.first.size()))) {
            double res = f.second(calc(s.substr(f.first.size())));
            dbg_end("calc_fun", res);
            return res;
        }
    }

    ERR = true;
    return 0;
}

bool is_dcr(const string &d) {
    string s = trim(d);

    if (s.front() != '(' || s.back() != ')')
        return false;

    int st = 1;
    for (int i = 1; s[i+1]; i++) {
        if (s[i] == '(') st++;
        else if (s[i] == ')') {
            st--;
            if (st == 0) {
                return false;
            }
        }
    }
    return true;
}

bool is_fun(const string &s) {
    for (auto &f: simple_funcs) {
        if (s.find(f.first) == 0 && is_dcr(s.substr(f.first.size())))
            return true;
    }

    return false;
}

bool check_bracket(const string &s) {
    int st = 0;
    for (auto c: s) {
        if (c == '(') st++;
        else if (c == ')') {
            st--;
            if (st < 0) {
                ERR = true;
                return false;
            }
        }
    }
    ERR |= st != 0;
    return st == 0;
}

bool is_num(const string &s) {
    int dot_pos = -1;
    int e_pos = -1;
    int e_sig_pos = -1;
    for (int i = 0; s[i]; i++) {
        switch(s[i]) {
            case '.':
                if (dot_pos >= 0) return false;
                dot_pos = i;
                break;
            case 'e':
                if (e_pos >= 0) return false;
                e_pos = i;
                break;
            case '+':
            case '-':
                if (e_sig_pos >= 0) return false;
                e_sig_pos = i;
                break;
            default:
                if (!isdigit(s[i])) return false;
        }
    }

    if (e_sig_pos >= 0) {
        if (e_pos < 0) return false;
        if (e_pos + 1 != e_sig_pos) return false;
        if (e_sig_pos == (int) s.length() - 1) return false;
    }

    if (e_pos >= 0) {
        if (e_pos == (int) s.length() - 1) return false;
        if (e_pos == 0) return false;
    }
    
    if (dot_pos == 0) return false;

    if (e_pos >= 0 && e_pos < dot_pos) return false;

    return true;
}

double conv_to_f(const string &s, bool after_dot = 0) {
    double res = 0, cf = 1;
    for (auto &c: s) {
        cf /= 10;
        if (after_dot) res += (c - '0') * cf;
        else res = res * 10 + c - '0';
    }
    return res;
}

double calc_num(string s) {
    dbg_start("calc_num", s);

    char e_sign = '+';
    for (auto &c: s) if (c == '-') e_sign = c;
    size_t dot_pos = s.find("."), e_pos = s.find("e"), es_pos = s.find(string() + e_sign);

    double mont = 0;
    int ord = 0;
    mont = conv_to_f(s.substr(0, min(dot_pos, e_pos)));
    if (dot_pos != string::npos)
        mont += conv_to_f(s.substr(dot_pos + 1, e_pos), true);
    if (e_pos != string::npos) {
        ord = round(conv_to_f(s.substr((es_pos == string::npos ? e_pos: es_pos) + 1)));
    }
    double res = mont;
    while (ord --) {
        if (e_sign == '+') res *= 10;
        else res /= 10;
    }
    dbg_end("calc_num", res);
    return res;
}

string normolize(const string &s) {
    string res = s;
    for (auto &c: res) c = tolower(c);

    return res;
}

string trim(const string &s) {

    int l = 0, r = s.length();
    while (l < r && isspace(s[l])) l++;
    while (r > l && isspace(s[r - 1])) r--;
    string res = s.substr(l, r - l);

    return res;
}