/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0867 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

stack<int> st;
int last = 0;
int lock_item() {
    if (!st.empty()) {
        int x = st.top();
        st.pop();
        return x;
    }
    return ++last;
}

void unlock_item(int x) {
    st.push(x);
}

int main() {
    int n, d; cin >> n >> d;
    pii dt [10000];
    int ans[10000];
    for (int i = 0; i < n; i++) {
        cin >> dt[i].first;
        dt[i].second = i;
    }
    sort(dt, dt + n);
    int l = 0, r = 0;
    while (r < n) {
        if (dt[r].first - dt[l].first <= d) {
            ans[dt[r++].second] = lock_item();
        } else {
            unlock_item(ans[dt[l++].second]);
        }
    }
    cout << last << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}