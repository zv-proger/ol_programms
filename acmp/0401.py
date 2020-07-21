#   Автор кода: Вадим Зинов (zv.proger@yandex.ru)
#   Решение задачи 0401 с сайта acmp.ru
   

from math import factorial as f

n, a, b = map(int, input().split())

a = f(a + n) // f (a) // f(n);
b = f(b + n) // f (b) // f(n);

print(a + b);