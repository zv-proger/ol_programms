block: funcs
template <class A> void doans(A a) { cout << a << ' '; }
template <class A, class... O> void doans(A a, O... o) { cout << a << ' '; doans(o...); exit(0); }
@#
