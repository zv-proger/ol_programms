block: funcs
template <class A> void print(A a) { cout << a << ' '; }
@#
template <class A> void doans(A a) { print(a); exit(0); }
@#
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }
@#
