block: funcs
void print(const double &a) { cout << fixed << setprecision(6) << a << ' '; }
@#
template <class A> void print(const A &a) { cout << a << ' '; }
@#
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
@#
template <class... O> void println(O &...o) { print(o...); cout << endl; }
@#
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
@#
template <class A> void read(A &a) { cin >> a; }
@#
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
@#
